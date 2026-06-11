#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_delta {

enum class P2PublicSurfaceDeltaKind : std::uint8_t {
    SnapshotDelta,
    SurfaceDelta,
    ProofDelta,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_delta
