#pragma once

#include <cstdint>

namespace kivo::playback::session_public {

enum class PlaybackSessionPublicRejectionReason : std::uint8_t {
    LifecyclePhaseAnchorMissing,
    ClassificationInvalid,
    SessionIdentityMissing,
    Unknown
};

} // namespace kivo::playback::session_public
