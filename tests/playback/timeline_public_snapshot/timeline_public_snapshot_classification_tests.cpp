#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/classification/timeline_public_snapshot_availability.h"
#include "playback/timeline_public_snapshot/classification/timeline_public_snapshot_freshness.h"
#include "playback/timeline_public_snapshot/classification/timeline_public_snapshot_audience.h"
#include "playback/timeline_public_snapshot/classification/timeline_public_snapshot_classification.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_classification_tests() {
    assert(static_cast<int>(TimelinePublicSnapshotAvailability::Available) != static_cast<int>(TimelinePublicSnapshotAvailability::Unknown));
    assert(static_cast<int>(TimelinePublicSnapshotFreshness::Fresh) != static_cast<int>(TimelinePublicSnapshotFreshness::Unknown));
    assert(static_cast<int>(TimelinePublicSnapshotAudience::PublicSafe) != static_cast<int>(TimelinePublicSnapshotAudience::Unknown));
    TimelinePublicSnapshotClassification c1;
    assert(c1.availability == TimelinePublicSnapshotAvailability::Unknown);
    assert(c1.freshness == TimelinePublicSnapshotFreshness::Unknown);
    assert(c1.audience == TimelinePublicSnapshotAudience::Unknown);
    TimelinePublicSnapshotClassification c2{TimelinePublicSnapshotAvailability::Available, TimelinePublicSnapshotFreshness::Fresh, TimelinePublicSnapshotAudience::PublicSafe};
    assert(c2.availability == TimelinePublicSnapshotAvailability::Available);
    assert(c2.audience == TimelinePublicSnapshotAudience::PublicSafe);
    std::cout << "  timeline_public_snapshot_classification_tests: ALL PASSED\n";
}
}
