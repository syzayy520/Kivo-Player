#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceCommitmentViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_commitment_view
