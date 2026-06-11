#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

enum class TrackTransitionPublicKind : std::uint8_t {
    Next,
    Previous,
    Direct,
    Unknown
};

} // namespace kivo::playback::track_transition_public
