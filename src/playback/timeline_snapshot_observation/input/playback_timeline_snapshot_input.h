#pragma once
#include "playback/orchestration/timeline/playback_timeline_snapshot.h"
namespace kivo::playback::timeline_snapshot_observation {
struct PlaybackTimelineSnapshotInput {
    kivo::playback::orchestration::PlaybackTimelineSnapshot snapshot{};
};
}
