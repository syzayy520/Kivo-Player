#pragma once

#include "../identity/p2_public_surface_availability_view_identity.h"
#include "../anchor/p2_public_surface_availability_view_anchor_set.h"
#include "../classification/p2_public_surface_availability_view_classification.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewEnvelope {
    P2PublicSurfaceAvailabilityViewIdentity identity{};
    P2PublicSurfaceAvailabilityViewAnchorSet anchors{};
    P2PublicSurfaceAvailabilityViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_availability_view
