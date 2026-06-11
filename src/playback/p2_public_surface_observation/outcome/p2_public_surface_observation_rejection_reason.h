#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_observation {

enum class P2PublicSurfaceObservationRejectionReason : std::uint8_t {
    AuditAnchorMissing,
    ClassificationInvalid,
    ObservationIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_observation
