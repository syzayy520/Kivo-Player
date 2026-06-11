#pragma once
#include "timeline_public_read_model_snapshot_anchor.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicSnapshotAnchorSet {
    TimelinePublicReadModelSnapshotAnchor read_model_anchor{};
};
}
