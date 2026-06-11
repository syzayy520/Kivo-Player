#pragma once

#include "../identity/p2_public_surface_confirmation_view_identity.h"
#include "../anchor/p2_public_surface_confirmation_view_anchor_set.h"
#include "../classification/p2_public_surface_confirmation_view_classification.h"

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewEnvelope {
    P2PublicSurfaceConfirmationViewIdentity identity{};
    P2PublicSurfaceConfirmationViewAnchorSet anchors{};
    P2PublicSurfaceConfirmationViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
