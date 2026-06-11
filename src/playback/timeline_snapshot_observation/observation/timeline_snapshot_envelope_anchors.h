#pragma once
#include "playback/timeline_result/identity/timeline_result_report_identity.h"
#include "../identity/timeline_snapshot_observation_identity.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotEnvelopeSourceRef { kivo::playback::timeline_result::TimelineResultReportIdentity report_identity{}; };
struct TimelineSnapshotEnvelopeInputRef { TimelineSnapshotObservationIdentity observation_identity{}; };
}
