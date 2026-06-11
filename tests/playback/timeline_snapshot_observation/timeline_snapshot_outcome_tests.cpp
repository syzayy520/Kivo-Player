#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/outcome/timeline_snapshot_observation_status.h"
#include "playback/timeline_snapshot_observation/outcome/timeline_snapshot_observation_outcome.h"
#include "playback/timeline_snapshot_observation/outcome/timeline_snapshot_rejection_reason.h"
#include "playback/timeline_snapshot_observation/outcome/timeline_snapshot_drop_reason.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_outcome_tests() {
    assert(static_cast<int>(TimelineSnapshotObservationStatus::Observed) != static_cast<int>(TimelineSnapshotObservationStatus::Rejected));
    assert(static_cast<int>(TimelineSnapshotObservationStatus::Dropped) != static_cast<int>(TimelineSnapshotObservationStatus::Unknown));
    assert(static_cast<int>(TimelineSnapshotRejectionReason::InputInvalid) != static_cast<int>(TimelineSnapshotRejectionReason::SnapshotUnavailable));
    assert(static_cast<int>(TimelineSnapshotRejectionReason::ObservationPolicyInvalid) != static_cast<int>(TimelineSnapshotRejectionReason::Unknown));
    assert(static_cast<int>(TimelineSnapshotDropReason::Superseded) != static_cast<int>(TimelineSnapshotDropReason::PriorityOverridden));
    assert(static_cast<int>(TimelineSnapshotDropReason::Unknown) != static_cast<int>(TimelineSnapshotDropReason::Superseded));
    TimelineSnapshotObservationOutcome o1;
    assert(o1.status == TimelineSnapshotObservationStatus::Unknown);
    assert(o1.identity.observation_id.value == 0);
    TimelineSnapshotObservationIdentity ident{.observation_id{10}, .sequence_id{20}, .generation{30}};
    TimelineSnapshotObservationOutcome o2{ident, TimelineSnapshotObservationStatus::Observed};
    assert(o2.identity.observation_id.value == 10);
    assert(o2.status == TimelineSnapshotObservationStatus::Observed);
    std::cout << "  timeline_snapshot_outcome_tests: ALL PASSED\n";
}
}
