#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

enum class P2PublicSurfaceCommitmentViewScope : std::uint8_t {
    PublicSurface,
    ActivationBoundary,
    CommitmentBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_commitment_view
