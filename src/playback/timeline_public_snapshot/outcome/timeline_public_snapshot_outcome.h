#pragma once
#include "../identity/timeline_public_snapshot_identity.h"
#include "timeline_public_snapshot_status.h"
namespace kivo::playback::timeline_public_snapshot {
struct TimelinePublicSnapshotOutcome {
    TimelinePublicSnapshotIdentity identity{};
    TimelinePublicSnapshotStatus status{TimelinePublicSnapshotStatus::Unknown};
};
}
