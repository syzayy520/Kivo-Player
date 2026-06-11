#pragma once
#include "timeline_user_status_surface_id.h"
#include "timeline_user_status_surface_sequence_id.h"
#include "timeline_user_status_surface_generation.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusSurfaceIdentity {
    TimelineUserStatusSurfaceId surface_id{};
    TimelineUserStatusSurfaceSequenceId sequence_id{};
    TimelineUserStatusSurfaceGeneration generation{};
};
}
