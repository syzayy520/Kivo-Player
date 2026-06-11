#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h"
#include "playback/timeline_public_snapshot/anchor/timeline_public_snapshot_anchor_set.h"
#include "playback/timeline_public_snapshot/classification/timeline_public_snapshot_classification.h"
#include "playback/timeline_public_snapshot/snapshot/timeline_public_snapshot_record.h"
#include "playback/timeline_public_snapshot/outcome/timeline_public_snapshot_outcome.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_boundary_tests() {
    TimelinePublicSnapshotIdentity ident{.snapshot_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident.snapshot_id.value == 1); assert(ident.sequence_id.value == 2); assert(ident.generation.value == 3);
    TimelinePublicSnapshotClassification cls{TimelinePublicSnapshotAvailability::Unavailable, TimelinePublicSnapshotFreshness::Stale, TimelinePublicSnapshotAudience::Internal};
    assert(cls.availability == TimelinePublicSnapshotAvailability::Unavailable);
    TimelinePublicSnapshotRecord rec;
    rec.envelope.identity = ident;
    assert(rec.envelope.identity.snapshot_id.value == 1);
    TimelinePublicSnapshotOutcome out{ident, TimelinePublicSnapshotStatus::Rejected};
    assert(out.identity.snapshot_id.value == 1);
    assert(out.status == TimelinePublicSnapshotStatus::Rejected);
    std::cout << "  timeline_public_snapshot_boundary_tests: ALL PASSED\n";
}
}
