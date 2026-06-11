#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_observation {

enum class P2PublicSurfaceObservationKind : std::uint8_t {
    ChainObservation,
    SurfaceObservation,
    ProofObservation,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_observation
