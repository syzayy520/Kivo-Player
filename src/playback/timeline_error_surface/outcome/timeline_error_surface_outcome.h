#pragma once
#include "../identity/timeline_error_surface_identity.h"
#include "timeline_error_surface_status.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineErrorSurfaceOutcome {
    TimelineErrorSurfaceIdentity identity{};
    TimelineErrorSurfaceStatus status{TimelineErrorSurfaceStatus::Unknown};
};
}
