#pragma once
#include "timeline_snapshot_source_kind.h"
#include "timeline_result_report_identity_source_ref.h"
#include "reported_timeline_result_source_ref.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineSnapshotSource {
    TimelineSnapshotSourceKind kind{TimelineSnapshotSourceKind::Unknown};
    TimelineResultReportIdentitySourceRef identity_source{};
    ReportedTimelineResultSourceRef reported_source{};
};
}
