#pragma once

#include "timeline_public_surface_boundary_lifecycle_phase_anchor.h"

namespace kivo::playback::lifecycle_phase {

struct PlaybackLifecyclePhaseAnchorSet {
    TimelinePublicSurfaceBoundaryLifecyclePhaseAnchor boundary_anchor{};
};

} // namespace kivo::playback::lifecycle_phase
