#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

enum class TrackTransitionPublicDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::track_transition_public
