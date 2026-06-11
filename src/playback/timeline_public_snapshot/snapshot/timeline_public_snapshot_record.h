#pragma once
#include "timeline_public_snapshot_envelope.h"
#include "playback_timeline_public_snapshot.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicSnapshotRecord {
    TimelinePublicSnapshotEnvelope envelope{};
    PlaybackTimelinePublicSnapshot snapshot{};
};
}
