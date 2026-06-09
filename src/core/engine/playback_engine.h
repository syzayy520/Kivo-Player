// src/core/engine/playback_engine.h - Playback engine core.
// Owns state transitions, receives commands, outputs events, returns results.
// Does NOT depend on real FFmpeg/D3D11/WASAPI/libmpv/Qt/UI.
#pragma once
#include "../command/playback_command.h"
#include "../state/playback_state_machine.h"
#include "../session/playback_session.h"
#include "../event/playback_event_sink.h"
#include "../result/playback_result.h"
#include <cstdint>

namespace kivo::playback {

class PlaybackEngine {
public:
    explicit PlaybackEngine(IPlaybackEventSink* sink);
    ~PlaybackEngine();

    auto execute(PlaybackCommand const& cmd) -> PlaybackResult;
    auto current_state() const noexcept -> PlaybackState { return state_machine_.current_state(); }
    auto has_active_session() const noexcept -> bool;

private:
    auto dispatch_open(CmdOpenMedia const& cmd) -> PlaybackResult;
    auto dispatch_play() -> PlaybackResult;
    auto dispatch_pause() -> PlaybackResult;
    auto dispatch_toggle_pause() -> PlaybackResult;
    auto dispatch_seek(MediaTime target) -> PlaybackResult;
    auto dispatch_stop() -> PlaybackResult;
    auto dispatch_close() -> PlaybackResult;
    auto dispatch_set_rate(double rate) -> PlaybackResult;
    auto dispatch_set_volume(double vol) -> PlaybackResult;
    auto dispatch_mute() -> PlaybackResult;
    auto dispatch_unmute() -> PlaybackResult;
    auto emit_state_changed(PlaybackState from, PlaybackState to) -> void;
    auto emit_error(PlaybackError const& err) -> void;
    auto next_session_id() -> SessionId;
    auto next_generation() -> GenerationId;

    IPlaybackEventSink* event_sink_;
    PlaybackStateMachine state_machine_;
    std::uint64_t next_session_id_{1};
    std::uint64_t next_command_id_{1};
};

} // namespace kivo::playback
