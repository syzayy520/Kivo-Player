#pragma once
#include "timeline_public_snapshot_delta_anchor.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicDeltaAnchorSet {
    TimelinePublicSnapshotDeltaAnchor snapshot_anchor{};
};
}
