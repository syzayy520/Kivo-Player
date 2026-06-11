#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

enum class P2PublicSurfaceCommitmentViewDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_surface_commitment_view
