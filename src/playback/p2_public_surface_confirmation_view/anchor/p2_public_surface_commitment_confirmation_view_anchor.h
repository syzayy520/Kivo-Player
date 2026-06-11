#pragma once

#include "playback/p2_public_surface_commitment_view/identity/p2_public_surface_commitment_view_identity.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceCommitmentConfirmationViewAnchor {
    kivo::playback::p2_public_surface_commitment_view::P2PublicSurfaceCommitmentViewIdentity commitment_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
