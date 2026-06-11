#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

enum class P2PublicSurfaceDeltaRejectionReason : std::uint8_t {
    SnapshotAnchorMissing,
    ClassificationInvalid,
    DeltaIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_delta
