#pragma once

#include "../identity/p2_public_surface_activation_view_identity.h"
#include "../anchor/p2_public_surface_activation_view_anchor_set.h"
#include "../classification/p2_public_surface_activation_view_classification.h"

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewCandidate {
    P2PublicSurfaceActivationViewIdentity identity{};
    P2PublicSurfaceActivationViewAnchorSet anchors{};
    P2PublicSurfaceActivationViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_activation_view
