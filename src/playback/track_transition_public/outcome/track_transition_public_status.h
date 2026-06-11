#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

enum class TrackTransitionPublicStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::track_transition_public
