#pragma once

#include "p2_public_surface_commitment_confirmation_view_anchor.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewAnchorSet {
    P2PublicSurfaceCommitmentConfirmationViewAnchor commitment_view_anchor{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
