#pragma once
#include "timeline_state_source_kind.h"
#include "timeline_request_identity_source_ref.h"
#include "timeline_snapshot_observation_source_ref.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateSource {
    TimelineStateSourceKind kind{TimelineStateSourceKind::Unknown};
    TimelineRequestIdentitySourceRef request_source{};
    TimelineSnapshotObservationSourceRef snapshot_source{};
};
}
