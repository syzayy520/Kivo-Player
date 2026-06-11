#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

enum class P2PublicSurfaceConfirmationViewKind : std::uint8_t {
    CommitmentConfirmed,
    SurfaceConfirmed,
    ProofConfirmed,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
