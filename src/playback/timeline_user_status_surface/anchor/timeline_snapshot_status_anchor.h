#pragma once
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_identity.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineSnapshotStatusAnchor {
    kivo::playback::timeline_snapshot_observation::TimelineSnapshotObservationIdentity snapshot_observation_identity{};
};
}
