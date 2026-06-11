#pragma once
#include "timeline_snapshot_observation_id.h"
#include "timeline_snapshot_observation_sequence_id.h"
#include "timeline_snapshot_observation_generation.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationIdentity {
    TimelineSnapshotObservationId observation_id{};
    TimelineSnapshotObservationSequenceId sequence_id{};
    TimelineSnapshotObservationGeneration generation{};
};
}
