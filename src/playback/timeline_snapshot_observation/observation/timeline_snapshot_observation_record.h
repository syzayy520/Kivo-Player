#pragma once
#include "timeline_snapshot_observation_envelope.h"
#include "observed_timeline_snapshot.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationRecord {
    TimelineSnapshotObservationEnvelope envelope{};
    ObservedTimelineSnapshot observed_snapshot{};
};
}
