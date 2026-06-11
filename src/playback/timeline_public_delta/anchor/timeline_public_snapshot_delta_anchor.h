#pragma once
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h"
namespace kivo::playback::timeline_public_delta {
struct TimelinePublicSnapshotDeltaAnchor {
    kivo::playback::timeline_public_snapshot::TimelinePublicSnapshotIdentity snapshot_identity{};
};
}
