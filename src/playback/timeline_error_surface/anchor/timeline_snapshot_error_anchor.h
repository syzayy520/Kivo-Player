#pragma once
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_identity.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineSnapshotErrorAnchor {
    kivo::playback::timeline_snapshot_observation::TimelineSnapshotObservationIdentity snapshot_observation_identity{};
};
}
