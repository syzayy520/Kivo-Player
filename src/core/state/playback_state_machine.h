// src/core/state/playback_state_machine.h - State transition rules.
// Depends on: core/state (PlaybackState), core/result, core/error.
// Does NOT depend on: command, engine, manager, pipeline, decoder, output, UI.
#pragma once
#include "../state/playback_state.h"
#include "../result/playback_result.h"
#include <optional>

namespace kivo::playback {

struct StateTransition {
    PlaybackState from;
    PlaybackState to;
};

constexpr auto is_valid_transition(PlaybackState from, PlaybackState to) -> bool;

struct PlaybackStateMachine {
    PlaybackState current{PlaybackState::Idle};

    auto try_transition(PlaybackState next) -> PlaybackResult;
    auto current_state() const noexcept -> PlaybackState { return current; }
    auto reset() noexcept -> void { current = PlaybackState::Idle; }
};

} // namespace kivo::playback
