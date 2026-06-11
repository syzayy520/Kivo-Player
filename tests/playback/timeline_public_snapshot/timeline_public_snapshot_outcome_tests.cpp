#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/outcome/timeline_public_snapshot_status.h"
#include "playback/timeline_public_snapshot/outcome/timeline_public_snapshot_rejection_reason.h"
#include "playback/timeline_public_snapshot/outcome/timeline_public_snapshot_drop_reason.h"
#include "playback/timeline_public_snapshot/outcome/timeline_public_snapshot_outcome.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_outcome_tests() {
    assert(static_cast<int>(TimelinePublicSnapshotStatus::Recorded) != static_cast<int>(TimelinePublicSnapshotStatus::Unknown));
    assert(static_cast<int>(TimelinePublicSnapshotRejectionReason::AnchorMissing) != static_cast<int>(TimelinePublicSnapshotRejectionReason::Unknown));
    assert(static_cast<int>(TimelinePublicSnapshotDropReason::Superseded) != static_cast<int>(TimelinePublicSnapshotDropReason::Unknown));
    TimelinePublicSnapshotOutcome out1;
    assert(out1.identity.snapshot_id.value == 0);
    assert(out1.status == TimelinePublicSnapshotStatus::Unknown);
    TimelinePublicSnapshotOutcome out2{{.snapshot_id{10}, .sequence_id{0}, .generation{0}}, TimelinePublicSnapshotStatus::Recorded};
    assert(out2.identity.snapshot_id.value == 10);
    assert(out2.status == TimelinePublicSnapshotStatus::Recorded);
    std::cout << "  timeline_public_snapshot_outcome_tests: ALL PASSED\n";
}
}
