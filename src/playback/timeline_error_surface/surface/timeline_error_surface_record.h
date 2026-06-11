#pragma once
#include "timeline_error_surface_envelope.h"
#include "playback_timeline_error_surface.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineErrorSurfaceRecord {
    TimelineErrorSurfaceEnvelope envelope{};
    PlaybackTimelineErrorSurface surface{};
};
}
