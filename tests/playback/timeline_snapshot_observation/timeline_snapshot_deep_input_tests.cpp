#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/input/timeline_result_report_record_input.h"
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_deep_input_tests() {
    TimelineResultReportRecordInput rri1;
    assert(rri1.report_record.envelope.identity.report_id.value == 0);
    TimelineSnapshotInput inp1;
    assert(inp1.kind == TimelineSnapshotInputKind::Unknown);
    std::cout << "  timeline_snapshot_deep_input_tests: ALL PASSED\n";
}
}
