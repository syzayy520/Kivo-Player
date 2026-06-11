#pragma once
#include "timeline_snapshot_input_kind.h"
#include "playback_timeline_snapshot_input.h"
#include "timeline_result_report_record_input.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotInput {
    TimelineSnapshotInputKind kind{TimelineSnapshotInputKind::Unknown};
    PlaybackTimelineSnapshotInput snapshot_input{};
    TimelineResultReportRecordInput report_record{};
};
}
