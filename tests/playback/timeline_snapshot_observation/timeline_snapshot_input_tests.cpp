#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input_kind.h"
#include "playback/timeline_snapshot_observation/input/playback_timeline_snapshot_input.h"
#include "playback/timeline_snapshot_observation/input/timeline_result_report_record_input.h"
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_input_tests() {
    assert(static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot) != static_cast<int>(TimelineSnapshotInputKind::ResultReportRecord));
    assert(static_cast<int>(TimelineSnapshotInputKind::Unknown) != static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot));
    PlaybackTimelineSnapshotInput si1; assert(si1.snapshot.session_id.value == 0); assert(si1.snapshot.position.value == 0);
    kivo::playback::orchestration::PlaybackTimelineSnapshot snap;
    snap.position.value = 100; snap.session_id.value = 42;
    PlaybackTimelineSnapshotInput si2{snap}; assert(si2.snapshot.position.value == 100);
    TimelineResultReportRecordInput rri1;
    assert(rri1.report_record.envelope.identity.report_id.value == 0);
    TimelineSnapshotInput inp1;
    assert(inp1.kind == TimelineSnapshotInputKind::Unknown);
    TimelineSnapshotInput inp2{TimelineSnapshotInputKind::TimelineSnapshot, si2, {}};
    assert(inp2.kind == TimelineSnapshotInputKind::TimelineSnapshot);
    assert(inp2.snapshot_input.snapshot.position.value == 100);
    TimelineSnapshotInput inp3{TimelineSnapshotInputKind::ResultReportRecord, {}, rri1};
    assert(inp3.kind == TimelineSnapshotInputKind::ResultReportRecord);
    assert(inp3.report_record.report_record.envelope.identity.report_id.value == 0);
    std::cout << "  timeline_snapshot_input_tests: ALL PASSED\n";
}
}
