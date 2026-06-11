#pragma once
#include "../identity/timeline_snapshot_observation_identity.h"
#include "timeline_snapshot_envelope_anchors.h"
#include "../policy/timeline_snapshot_observation_policy.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotObservationEnvelope {
    TimelineSnapshotObservationIdentity identity{};
    TimelineSnapshotEnvelopeSourceRef source_ref{};
    TimelineSnapshotEnvelopeInputRef input_ref{};
    TimelineSnapshotObservationPolicy policy{};
};
}
