#pragma once

#include "timeline_public_surface_boundary_envelope.h"
#include "playback_timeline_public_surface_boundary.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryRecord {
    TimelinePublicSurfaceBoundaryEnvelope envelope{};
    PlaybackTimelinePublicSurfaceBoundary boundary{};
};

} // namespace kivo::playback::timeline_public_surface_boundary
