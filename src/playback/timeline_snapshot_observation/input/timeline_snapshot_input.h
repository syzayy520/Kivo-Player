#pragma once
#include "timeline_snapshot_input_kind.h"
#include "timeline_snapshot_input_ref.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotInput {
    TimelineSnapshotInputKind kind{TimelineSnapshotInputKind::Unknown};
    TimelineSnapshotInputRef ref{};
};
}
