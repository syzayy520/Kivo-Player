#pragma once
#include "../identity/timeline_public_delta_identity.h"
#include "../anchor/timeline_public_delta_anchor_set.h"
#include "../classification/timeline_public_delta_classification.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaCandidate {
    TimelinePublicDeltaIdentity identity{};
    TimelinePublicDeltaAnchorSet anchors{};
    TimelinePublicDeltaClassification classification{};
};
}
