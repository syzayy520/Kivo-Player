#pragma once

#include "p2_public_surface_commitment_view_id.h"
#include "p2_public_surface_commitment_view_sequence_id.h"
#include "p2_public_surface_commitment_view_generation.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewIdentity {
    P2PublicSurfaceCommitmentViewId view_id{};
    P2PublicSurfaceCommitmentViewSequenceId sequence_id{};
    P2PublicSurfaceCommitmentViewGeneration generation{};

    bool operator==(const P2PublicSurfaceCommitmentViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_commitment_view
