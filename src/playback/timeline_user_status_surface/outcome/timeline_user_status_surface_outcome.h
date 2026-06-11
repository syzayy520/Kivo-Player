#pragma once
#include "../identity/timeline_user_status_surface_identity.h"
#include "timeline_user_status_surface_status.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusSurfaceOutcome {
    TimelineUserStatusSurfaceIdentity identity{};
    TimelineUserStatusSurfaceStatus status{TimelineUserStatusSurfaceStatus::Unknown};
};
}
