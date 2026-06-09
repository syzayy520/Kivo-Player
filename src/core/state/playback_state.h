// src/core/state/playback_state.h - Playback state enumeration.
// Depends on: nothing (leaf).
#pragma once

namespace kivo::playback {

enum class PlaybackState {
    Idle,
    Opening,
    Probing,
    Ready,
    Playing,
    Paused,
    Seeking,
    Buffering,
    Ended,
    Error,
    Closing,
    Closed,
};

constexpr auto to_string(PlaybackState s) -> const char*;

} // namespace kivo::playback
