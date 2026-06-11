#pragma once
#include "../identity/timeline_public_snapshot_identity.h"
#include "../anchor/timeline_public_snapshot_anchor_set.h"
#include "../classification/timeline_public_snapshot_classification.h"
namespace kivo::playback::timeline_public_snapshot {
struct PlaybackTimelinePublicSnapshot {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotAnchorSet anchors{};
    TimelinePublicSnapshotClassification classification{};
};
}
