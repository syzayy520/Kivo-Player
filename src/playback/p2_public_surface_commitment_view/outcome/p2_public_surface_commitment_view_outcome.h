#pragma once

#include "../identity/p2_public_surface_commitment_view_identity.h"
#include "p2_public_surface_commitment_view_status.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewOutcome {
    P2PublicSurfaceCommitmentViewIdentity identity{};
    P2PublicSurfaceCommitmentViewStatus status{P2PublicSurfaceCommitmentViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceCommitmentViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_commitment_view
