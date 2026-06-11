#pragma once
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_identity.h"
namespace kivo::playback::timeline_chain_integrity {
struct TimelineSnapshotChainAnchor { kivo::playback::timeline_snapshot_observation::TimelineSnapshotObservationIdentity snapshot_observation_identity{}; };
}
