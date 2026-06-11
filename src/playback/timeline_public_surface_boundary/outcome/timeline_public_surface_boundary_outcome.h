#pragma once

#include "../identity/timeline_public_surface_boundary_identity.h"
#include "timeline_public_surface_boundary_status.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryOutcome {
    TimelinePublicSurfaceBoundaryIdentity identity{};
    TimelinePublicSurfaceBoundaryStatus status{TimelinePublicSurfaceBoundaryStatus::Unknown};

    bool operator==(const TimelinePublicSurfaceBoundaryOutcome& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
