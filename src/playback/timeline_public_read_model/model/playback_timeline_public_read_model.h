#pragma once
#include "../identity/timeline_public_read_model_identity.h"
#include "../anchor/timeline_public_read_anchor_set.h"
#include "../classification/timeline_public_read_model_classification.h"
namespace kivo::playback::timeline_public_read_model {
struct PlaybackTimelinePublicReadModel {
    TimelinePublicReadModelIdentity identity{};
    TimelinePublicReadAnchorSet anchors{};
    TimelinePublicReadModelClassification classification{};
};
}
