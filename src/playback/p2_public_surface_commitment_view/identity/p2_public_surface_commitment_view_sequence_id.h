#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceCommitmentViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_commitment_view
