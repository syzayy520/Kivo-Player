#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_snapshot {

enum class P2PublicSurfaceSnapshotRejectionReason : std::uint8_t {
    ObservationAnchorMissing,
    ClassificationInvalid,
    SnapshotIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_snapshot
