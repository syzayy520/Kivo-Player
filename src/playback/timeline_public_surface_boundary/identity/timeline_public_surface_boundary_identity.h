#pragma once

#include "timeline_public_surface_boundary_id.h"
#include "timeline_public_surface_boundary_sequence_id.h"
#include "timeline_public_surface_boundary_generation.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicSurfaceBoundaryIdentity {
    TimelinePublicSurfaceBoundaryId boundary_id{};
    TimelinePublicSurfaceBoundarySequenceId sequence_id{};
    TimelinePublicSurfaceBoundaryGeneration generation{};

    bool operator==(const TimelinePublicSurfaceBoundaryIdentity& other) const = default;
};

} // namespace kivo::playback::timeline_public_surface_boundary
