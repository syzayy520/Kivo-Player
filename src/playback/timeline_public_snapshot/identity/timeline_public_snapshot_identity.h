#pragma once
#include "timeline_public_snapshot_id.h"
#include "timeline_public_snapshot_sequence_id.h"
#include "timeline_public_snapshot_generation.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicSnapshotIdentity {
    TimelinePublicSnapshotId snapshot_id{};
    TimelinePublicSnapshotSequenceId sequence_id{};
    TimelinePublicSnapshotGeneration generation{};
};
}
