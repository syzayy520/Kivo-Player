#pragma once

#include <cstdint>

namespace kivo::playback::lifecycle_phase {

enum class PlaybackLifecyclePhaseRejectionReason : std::uint8_t {
    BoundaryAnchorMissing,
    ClassificationInvalid,
    PhaseIdentityMissing,
    Unknown
};

} // namespace kivo::playback::lifecycle_phase
