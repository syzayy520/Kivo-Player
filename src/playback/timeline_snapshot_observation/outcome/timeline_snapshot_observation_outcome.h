#pragma once
#include "../identity/timeline_snapshot_observation_identity.h"
#include "timeline_snapshot_observation_status.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationOutcome {
    TimelineSnapshotObservationIdentity identity{};
    TimelineSnapshotObservationStatus status{TimelineSnapshotObservationStatus::Unknown};
};
}
