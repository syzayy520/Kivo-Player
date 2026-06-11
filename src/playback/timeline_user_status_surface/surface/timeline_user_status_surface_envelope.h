#pragma once
#include "../identity/timeline_user_status_surface_identity.h"
#include "../anchor/timeline_user_status_anchor_set.h"
#include "../classification/timeline_user_status_classification.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineUserStatusSurfaceEnvelope {
    TimelineUserStatusSurfaceIdentity identity{};
    TimelineUserStatusAnchorSet anchors{};
    TimelineUserStatusClassification classification{};
};
}
