#pragma once
#include "timeline_error_surface_id.h"
#include "timeline_error_surface_sequence_id.h"
#include "timeline_error_surface_generation.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineErrorSurfaceIdentity {
    TimelineErrorSurfaceId surface_id{};
    TimelineErrorSurfaceSequenceId sequence_id{};
    TimelineErrorSurfaceGeneration generation{};
};
}
