#pragma once
#include "../identity/timeline_snapshot_observation_identity.h"
#include "playback/orchestration/timeline/playback_timeline_snapshot.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotCandidate {
    TimelineSnapshotObservationIdentity identity{};
    kivo::playback::orchestration::PlaybackTimelineSnapshot snapshot{};
};
}
