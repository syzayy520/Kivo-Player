#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

enum class P2PublicSurfaceCommitmentViewKind : std::uint8_t {
    ActivationCommitted,
    SurfaceCommitted,
    ProofCommitted,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_commitment_view
