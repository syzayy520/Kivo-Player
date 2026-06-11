#pragma once

#include "playback/timeline_public_surface_boundary/identity/timeline_public_surface_boundary_identity.h"

namespace kivo::playback::lifecycle_phase {

struct TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor {
    kivo::playback::timeline_public_surface_boundary::TimelinePublicSurfaceBoundaryIdentity boundary_identity{};
};

} // namespace kivo::playback::lifecycle_phase
