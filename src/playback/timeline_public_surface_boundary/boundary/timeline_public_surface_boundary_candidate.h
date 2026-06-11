#pragma once

#include "../identity/timeline_public_surface_boundary_identity.h"
#include "../anchor/timeline_public_surface_boundary_anchor_set.h"
#include "../classification/timeline_public_surface_boundary_classification.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryCandidate {
    TimelinePublicSurfaceBoundaryIdentity identity{};
    TimelinePublicSurfaceBoundaryAnchorSet anchors{};
    TimelinePublicSurfaceBoundaryClassification classification{};
};

} // namespace kivo::playback::timeline_public_surface_boundary
