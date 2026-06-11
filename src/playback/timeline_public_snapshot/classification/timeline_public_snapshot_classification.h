#pragma once
#include "timeline_public_snapshot_availability.h"
#include "timeline_public_snapshot_freshness.h"
#include "timeline_public_snapshot_audience.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicSnapshotClassification {
    TimelinePublicSnapshotAvailability availability{TimelinePublicSnapshotAvailability::Unknown};
    TimelinePublicSnapshotFreshness freshness{TimelinePublicSnapshotFreshness::Unknown};
    TimelinePublicSnapshotAudience audience{TimelinePublicSnapshotAudience::Unknown};
};
}
