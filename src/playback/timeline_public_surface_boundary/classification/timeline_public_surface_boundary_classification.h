#pragma once

#include "timeline_public_surface_boundary_kind.h"
#include "timeline_public_surface_boundary_scope.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryClassification {
    TimelinePublicSurfaceBoundaryKind kind{TimelinePublicSurfaceBoundaryKind::Unknown};
    TimelinePublicSurfaceBoundaryScope scope{TimelinePublicSurfaceBoundaryScope::Unknown};

    bool operator==(const TimelinePublicSurfaceBoundaryClassification& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
