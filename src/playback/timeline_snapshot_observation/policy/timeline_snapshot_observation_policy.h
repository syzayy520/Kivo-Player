#pragma once
#include "timeline_snapshot_observation_kind.h"
#include "timeline_snapshot_fidelity_policy.h"
#include "timeline_snapshot_priority.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationPolicy {
    TimelineSnapshotObservationKind observation_kind{TimelineSnapshotObservationKind::Unknown};
    TimelineSnapshotFidelityPolicy fidelity_policy{TimelineSnapshotFidelityPolicy::Unknown};
    TimelineSnapshotPriority priority{TimelineSnapshotPriority::Unknown};
};
}
