#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input_kind.h"
#include "playback/timeline_snapshot_observation/input/playback_timeline_snapshot_input.h"
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_input_tests() {
    // kind tests
    assert(static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot) != static_cast<int>(TimelineSnapshotInputKind::ResultReportRecord));
    assert(static_cast<int>(TimelineSnapshotInputKind::Unknown) != static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot));
    // PlaybackTimelineSnapshotInput (snapshot chain)
    PlaybackTimelineSnapshotInput si1; assert(si1.snapshot.session_id.value == 0); assert(si1.snapshot.position.value == 0);
    ::kivo::playback::orchestration::PlaybackTimelineSnapshot snap;
    snap.position.value = 100; snap.session_id.value = 42;
    PlaybackTimelineSnapshotInput si2{snap}; assert(si2.snapshot.position.value == 100);
    // TimelineSnapshotInput (lightweight - kind + identity ref)
    TimelineSnapshotInput inp1;
    assert(inp1.kind == TimelineSnapshotInputKind::Unknown);
    assert(inp1.ref.kind == TimelineSnapshotInputKind::Unknown);
    assert(inp1.ref.report_identity.report_id.value == 0);
    assert(inp1.ref.report_identity.sequence_id.value == 0);
    assert(inp1.ref.report_identity.generation.value == 0);
    TimelineSnapshotInput inp2{TimelineSnapshotInputKind::ResultReportRecord};
    assert(inp2.kind == TimelineSnapshotInputKind::ResultReportRecord);
    assert(inp2.ref.kind == TimelineSnapshotInputKind::Unknown);
    TimelineSnapshotInput inp3;
    inp3.kind = TimelineSnapshotInputKind::TimelineSnapshot;
    assert(inp3.kind == TimelineSnapshotInputKind::TimelineSnapshot);
    std::cout << "  timeline_snapshot_input_tests: ALL PASSED\n";
}
}
