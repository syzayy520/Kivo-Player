// src/core/engine/playback_engine.cpp - Playback engine implementation.
#include "playback_engine.h"
#include "../state/playback_state_machine.h"
#include "../event/playback_event_sink.h"
#include "../result/playback_result.h"
#include "../error/playback_error.h"
#include <utility>
#include <cmath>
#include <cctype>

namespace kivo::playback {

PlaybackEngine::PlaybackEngine(IPlaybackEventSink* sink)
    : event_sink_(sink) {}

PlaybackEngine::~PlaybackEngine() = default;

auto PlaybackEngine::execute(PlaybackCommand const& cmd) -> PlaybackResult {
    // Dispatch based on command type
    if (std::holds_alternative<CmdOpenMedia>(cmd)) {
        auto const& c = std::get<CmdOpenMedia>(cmd);
        return dispatch_open(c);
    }
    if (std::holds_alternative<CmdPlay>(cmd)) { return dispatch_play(); }
    if (std::holds_alternative<CmdPause>(cmd)) { return dispatch_pause(); }
    if (std::holds_alternative<CmdTogglePause>(cmd)) { return dispatch_toggle_pause(); }
    if (std::holds_alternative<CmdSeek>(cmd)) {
        return dispatch_seek(std::get<CmdSeek>(cmd).target);
    }
    if (std::holds_alternative<CmdStop>(cmd)) { return dispatch_stop(); }
    if (std::holds_alternative<CmdClose>(cmd)) { return dispatch_close(); }
    if (std::holds_alternative<CmdSetPlaybackRate>(cmd)) {
        return dispatch_set_rate(std::get<CmdSetPlaybackRate>(cmd).rate);
    }
    if (std::holds_alternative<CmdSetVolume>(cmd)) {
        return dispatch_set_volume(std::get<CmdSetVolume>(cmd).volume);
    }
    if (std::holds_alternative<CmdMute>(cmd)) { return dispatch_mute(); }
    if (std::holds_alternative<CmdUnmute>(cmd)) { return dispatch_unmute(); }
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
}

auto PlaybackEngine::dispatch_open(CmdOpenMedia const& c) -> PlaybackResult {
    // Validate: source non-empty after trim
    auto trimmed = c.source;
    while (!trimmed.empty() && std::isspace(static_cast<unsigned char>(trimmed[0]))) trimmed.erase(0, 1);
    while (!trimmed.empty() && std::isspace(static_cast<unsigned char>(trimmed.back()))) trimmed.pop_back();
    if (trimmed.empty()) {
        emit_error(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
    }
    // State check: only Idle can open
    if (state_machine_.current_state() != PlaybackState::Idle) {
        emit_error(PlaybackError{PlaybackErrorType::InvalidStateTransition});
        return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidStateTransition});
    }
    // Idle -> Opening
    auto r1 = state_machine_.try_transition(PlaybackState::Opening);
    if (!r1.is_success()) { emit_error(PlaybackError{PlaybackErrorType::InternalError}); return r1; }
    emit_state_changed(PlaybackState::Idle, PlaybackState::Opening);
    // Opening -> Ready (P0-001 synthetic shortcut, no real probe)
    auto r2 = state_machine_.try_transition(PlaybackState::Ready);
    if (!r2.is_success()) { emit_error(PlaybackError{PlaybackErrorType::InternalError}); return r2; }
    emit_state_changed(PlaybackState::Opening, PlaybackState::Ready);
    // DO NOT emit MediaOpened / MediaReady (P0-001 rule)
    // DO NOT create real session with metadata (P0-001 rule)
    (void)next_session_id(); // advance for next open
    return PlaybackResult::success();
}

auto PlaybackEngine::dispatch_play() -> PlaybackResult {
    auto s = state_machine_.current_state();
    if (s == PlaybackState::Ready || s == PlaybackState::Paused) {
        auto next = (s == PlaybackState::Ready) ? PlaybackState::Playing : PlaybackState::Playing;
        auto r = state_machine_.try_transition(next);
        if (!r.is_success()) return r;
        emit_state_changed(s, next);
        // emit PlaybackStarted (simplified)
        return PlaybackResult::success();
    }
    emit_error(PlaybackError{PlaybackErrorType::InvalidStateTransition});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidStateTransition});
}

auto PlaybackEngine::dispatch_pause() -> PlaybackResult {
    if (state_machine_.current_state() == PlaybackState::Playing) {
        auto r = state_machine_.try_transition(PlaybackState::Paused);
        if (!r.is_success()) return r;
        emit_state_changed(PlaybackState::Playing, PlaybackState::Paused);
        return PlaybackResult::success();
    }
    emit_error(PlaybackError{PlaybackErrorType::InvalidStateTransition});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidStateTransition});
}

auto PlaybackEngine::dispatch_toggle_pause() -> PlaybackResult {
    auto s = state_machine_.current_state();
    if (s == PlaybackState::Playing) { return dispatch_pause(); }
    if (s == PlaybackState::Paused) { return dispatch_play(); }
    emit_error(PlaybackError{PlaybackErrorType::InvalidStateTransition});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidStateTransition});
}

auto PlaybackEngine::dispatch_seek(MediaTime target) -> PlaybackResult {
    // Validate payload first
    if (target < 0) {
        emit_error(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
    }
    // Valid payload but UnsupportedCapability (no real seek in P0-001)
    emit_error(PlaybackError{PlaybackErrorType::UnsupportedCapability});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::UnsupportedCapability});
}

auto PlaybackEngine::dispatch_stop() -> PlaybackResult {
    auto s = state_machine_.current_state();
    if (s == PlaybackState::Ready || s == PlaybackState::Playing || s == PlaybackState::Paused || s == PlaybackState::Ended || s == PlaybackState::Error) {
        auto r = state_machine_.try_transition(PlaybackState::Idle);
        if (!r.is_success()) return r;
        emit_state_changed(s, PlaybackState::Idle);
        return PlaybackResult::success();
    }
    emit_error(PlaybackError{PlaybackErrorType::InvalidStateTransition});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidStateTransition});
}

auto PlaybackEngine::dispatch_close() -> PlaybackResult {
    auto s = state_machine_.current_state();
    if (s == PlaybackState::Closed) {
        // Idempotent: Closed + Close = Success, no event
        return PlaybackResult::success();
    }
    // Any non-Closed -> Closing -> Closed
    auto r1 = state_machine_.try_transition(PlaybackState::Closing);
    if (!r1.is_success()) { emit_error(PlaybackError{PlaybackErrorType::InternalError}); return r1; }
    emit_state_changed(s, PlaybackState::Closing);
    auto r2 = state_machine_.try_transition(PlaybackState::Closed);
    if (!r2.is_success()) { emit_error(PlaybackError{PlaybackErrorType::InternalError}); return r2; }
    emit_state_changed(PlaybackState::Closing, PlaybackState::Closed);
    return PlaybackResult::success();
}

auto PlaybackEngine::dispatch_set_rate(double rate) -> PlaybackResult {
    if (rate < 0.25 || rate > 4.0 || !std::isfinite(rate)) {
        emit_error(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
    }
    emit_error(PlaybackError{PlaybackErrorType::UnsupportedCapability});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::UnsupportedCapability});
}

auto PlaybackEngine::dispatch_set_volume(double vol) -> PlaybackResult {
    if (vol < 0.0 || vol > 1.0 || !std::isfinite(vol)) {
        emit_error(PlaybackError{PlaybackErrorType::InvalidCommand});
        return PlaybackResult::failure(PlaybackError{PlaybackErrorType::InvalidCommand});
    }
    emit_error(PlaybackError{PlaybackErrorType::UnsupportedCapability});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::UnsupportedCapability});
}

auto PlaybackEngine::dispatch_mute() -> PlaybackResult {
    emit_error(PlaybackError{PlaybackErrorType::UnsupportedCapability});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::UnsupportedCapability});
}

auto PlaybackEngine::dispatch_unmute() -> PlaybackResult {
    emit_error(PlaybackError{PlaybackErrorType::UnsupportedCapability});
    return PlaybackResult::failure(PlaybackError{PlaybackErrorType::UnsupportedCapability});
}

void PlaybackEngine::emit_state_changed(PlaybackState from, PlaybackState to) {
    if (event_sink_) {
        event_sink_->on_event(EvStateChanged{from, to});
    }
}

void PlaybackEngine::emit_error(PlaybackError const& err) {
    if (event_sink_) {
        event_sink_->on_event(EvErrorRaised{err});
    }
}

auto PlaybackEngine::next_session_id() -> SessionId {
    return SessionId{next_session_id_++};
}

} // namespace kivo::playback
