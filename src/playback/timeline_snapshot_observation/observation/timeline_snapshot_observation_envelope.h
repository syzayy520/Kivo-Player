#pragma once
#include "../identity/timeline_snapshot_observation_identity.h"
#include "../source/timeline_snapshot_source.h"
#include "../input/timeline_snapshot_input.h"
#include "../policy/timeline_snapshot_observation_policy.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationEnvelope {
    TimelineSnapshotObservationIdentity identity{};
    TimelineSnapshotSource source{};
    TimelineSnapshotInput input{};
    TimelineSnapshotObservationPolicy policy{};
};
}
