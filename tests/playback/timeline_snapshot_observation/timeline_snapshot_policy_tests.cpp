#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/policy/timeline_snapshot_observation_kind.h"
#include "playback/timeline_snapshot_observation/policy/timeline_snapshot_fidelity_policy.h"
#include "playback/timeline_snapshot_observation/policy/timeline_snapshot_priority.h"
#include "playback/timeline_snapshot_observation/policy/timeline_snapshot_observation_policy.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_policy_tests() {
    assert(static_cast<int>(TimelineSnapshotObservationKind::SnapshotOnly) != static_cast<int>(TimelineSnapshotObservationKind::ResultLinked));
    assert(static_cast<int>(TimelineSnapshotObservationKind::Unknown) != static_cast<int>(TimelineSnapshotObservationKind::SnapshotOnly));
    assert(static_cast<int>(TimelineSnapshotFidelityPolicy::PreservePosition) != static_cast<int>(TimelineSnapshotFidelityPolicy::PreserveSession));
    assert(static_cast<int>(TimelineSnapshotFidelityPolicy::Unknown) != static_cast<int>(TimelineSnapshotFidelityPolicy::PreserveUnknown));
    assert(static_cast<int>(TimelineSnapshotPriority::Low) != static_cast<int>(TimelineSnapshotPriority::High));
    assert(static_cast<int>(TimelineSnapshotPriority::Unknown) != static_cast<int>(TimelineSnapshotPriority::Normal));
    TimelineSnapshotObservationPolicy p1;
    assert(p1.observation_kind == TimelineSnapshotObservationKind::Unknown);
    assert(p1.fidelity_policy == TimelineSnapshotFidelityPolicy::Unknown);
    assert(p1.priority == TimelineSnapshotPriority::Unknown);
    TimelineSnapshotObservationPolicy p2{TimelineSnapshotObservationKind::ResultLinked, TimelineSnapshotFidelityPolicy::PreservePosition, TimelineSnapshotPriority::High};
    assert(p2.observation_kind == TimelineSnapshotObservationKind::ResultLinked);
    assert(p2.fidelity_policy == TimelineSnapshotFidelityPolicy::PreservePosition);
    assert(p2.priority == TimelineSnapshotPriority::High);
    std::cout << "  timeline_snapshot_policy_tests: ALL PASSED\n";
}
}
