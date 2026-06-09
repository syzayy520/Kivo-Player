// src/core/state/playback_state_machine.cpp - State machine implementation.
#include "playback_state_machine.h"
#include "../state/playback_state.h"
#include "../result/playback_result.h"
#include <array>

namespace kivo::playback {

constexpr auto is_valid_transition(PlaybackState from, PlaybackState to) -> bool {
    using P = PlaybackState;
    struct Rule { P from; P to; };
    constexpr Rule rules[] = {
        {P::Idle, P::Opening},
        {P::Idle, P::Closing},
        {P::Opening, P::Probing}, {P::Opening, P::Ready},
        {P::Probing, P::Ready},
        {P::Ready, P::Playing}, {P::Ready, P::Seeking},
        {P::Playing, P::Paused}, {P::Playing, P::Seeking}, {P::Playing, P::Ended},
        {P::Paused, P::Playing}, {P::Paused, P::Seeking},
        {P::Seeking, P::Playing}, {P::Seeking, P::Paused},
        {P::Buffering, P::Playing}, {P::Buffering, P::Ended},
        {P::Ready, P::Idle},
        {P::Playing, P::Idle}, {P::Paused, P::Idle},
        {P::Ended, P::Idle}, {P::Error, P::Idle},
        {P::Error, P::Closing},
        {P::Closing, P::Closed},
        {P::Closed, P::Idle}, {P::Closed, P::Opening},
    };
    for (auto const& r : rules) {
        if (r.from == from && r.to == to) return true;
    }
    return false;
}

auto PlaybackStateMachine::try_transition(PlaybackState next) -> PlaybackResult {
    if (!is_valid_transition(current, next)) {
        return PlaybackResult::failure(
            PlaybackError{PlaybackErrorType::InvalidStateTransition});
    }
    current = next;
    return PlaybackResult::success();
}

} // namespace kivo::playback
