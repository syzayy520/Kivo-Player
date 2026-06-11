#pragma once

#include <cstdint>

namespace kivo::playback::track_transition_public {

enum class TrackTransitionPublicRejectionReason : std::uint8_t {
    BufferingAnchorMissing,
    ClassificationInvalid,
    TransitionIdentityMissing,
    Unknown
};

} // namespace kivo::playback::track_transition_public
