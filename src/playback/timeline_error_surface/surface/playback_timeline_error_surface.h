#pragma once
#include "../identity/timeline_error_surface_identity.h"
#include "../anchor/timeline_error_anchor_set.h"
#include "../classification/timeline_error_classification.h"
namespace kivo::playback::timeline_error_surface {
struct PlaybackTimelineErrorSurface {
    TimelineErrorSurfaceIdentity identity{};
    TimelineErrorAnchorSet anchors{};
    TimelineErrorClassification classification{};
};
}
