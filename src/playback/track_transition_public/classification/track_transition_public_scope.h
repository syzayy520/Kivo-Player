#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

enum class TrackTransitionPublicScope : std::uint8_t {
    PublicSurface,
    Buffering,
    Timeline,
    Unknown
};

} // namespace kivo::playback::track_transition_public
