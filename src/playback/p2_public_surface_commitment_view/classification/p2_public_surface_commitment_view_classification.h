#pragma once

#include "p2_public_surface_commitment_view_kind.h"
#include "p2_public_surface_commitment_view_scope.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewClassification {
    P2PublicSurfaceCommitmentViewKind kind{P2PublicSurfaceCommitmentViewKind::Unknown};
    P2PublicSurfaceCommitmentViewScope scope{P2PublicSurfaceCommitmentViewScope::Unknown};

    bool operator==(const P2PublicSurfaceCommitmentViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_commitment_view
