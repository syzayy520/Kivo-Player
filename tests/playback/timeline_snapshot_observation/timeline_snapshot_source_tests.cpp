#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/source/timeline_snapshot_source_kind.h"
#include "playback/timeline_snapshot_observation/source/timeline_result_report_identity_source_ref.h"
#include "playback/timeline_snapshot_observation/source/reported_timeline_result_source_ref.h"
#include "playback/timeline_snapshot_observation/source/timeline_snapshot_source.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_source_tests() {
    assert(static_cast<int>(TimelineSnapshotSourceKind::ResultReportIdentity) != static_cast<int>(TimelineSnapshotSourceKind::ReportedResult));
    assert(static_cast<int>(TimelineSnapshotSourceKind::Unknown) != static_cast<int>(TimelineSnapshotSourceKind::Synthetic));
    TimelineResultReportIdentitySourceRef ir1; assert(ir1.report_identity.report_id.value == 0);
    kivo::playback::timeline_result::TimelineResultReportIdentity ident{.report_id{5}, .sequence_id{6}, .generation{7}};
    TimelineResultReportIdentitySourceRef ir2{ident}; assert(ir2.report_identity.report_id.value == 5);
    ReportedTimelineResultSourceRef rr1; assert(rr1.reported_result.identity.report_id.value == 0);
    TimelineSnapshotSource src1;
    assert(src1.kind == TimelineSnapshotSourceKind::Unknown);
    TimelineSnapshotSource src2{TimelineSnapshotSourceKind::ResultReportIdentity, ir2, {}};
    assert(src2.kind == TimelineSnapshotSourceKind::ResultReportIdentity);
    assert(src2.identity_source.report_identity.report_id.value == 5);
    std::cout << "  timeline_snapshot_source_tests: ALL PASSED\n";
}
}
