#pragma once
#include "timeline_snapshot_input_kind.h"
#include "playback/timeline_result/identity/timeline_result_report_identity.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotInputRef {
    TimelineSnapshotInputKind kind{TimelineSnapshotInputKind::Unknown};
    kivo::playback::timeline_result::TimelineResultReportIdentity report_identity{};
};
}