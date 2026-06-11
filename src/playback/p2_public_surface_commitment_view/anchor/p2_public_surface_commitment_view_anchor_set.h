#pragma once

#include "p2_public_surface_activation_commitment_view_anchor.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewAnchorSet {
    P2PublicSurfaceActivationCommitmentViewAnchor activation_anchor{};
};

} // namespace kivo::playback::p2_public_surface_commitment_view
