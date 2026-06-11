#pragma once

#include "../identity/p2_public_surface_commitment_view_identity.h"
#include "../anchor/p2_public_surface_commitment_view_anchor_set.h"
#include "../classification/p2_public_surface_commitment_view_classification.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewCandidate {
    P2PublicSurfaceCommitmentViewIdentity identity{};
    P2PublicSurfaceCommitmentViewAnchorSet anchors{};
    P2PublicSurfaceCommitmentViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_commitment_view
