#pragma once
#include "timeline_user_status_surface_envelope.h"
#include "playback_timeline_user_status_surface.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusSurfaceRecord {
    TimelineUserStatusSurfaceEnvelope envelope{};
    PlaybackTimelineUserStatusSurface surface{};
};
}
