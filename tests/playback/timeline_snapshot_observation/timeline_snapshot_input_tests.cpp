#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/input/timeline_snapshot_input_kind.h"
#include "playback/timeline_snapshot_observation/input/playback_timeline_snapshot_input.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_input_tests() {
    assert(static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot) != static_cast<int>(TimelineSnapshotInputKind::ResultReportRecord));
    assert(static_cast<int>(TimelineSnapshotInputKind::Unknown) != static_cast<int>(TimelineSnapshotInputKind::TimelineSnapshot));
    PlaybackTimelineSnapshotInput si1; assert(si1.snapshot.session_id.value == 0); assert(si1.snapshot.position.value == 0);
    kivo::playback::orchestration::PlaybackTimelineSnapshot snap;
    snap.position.value = 100; snap.session_id.value = 42;
    PlaybackTimelineSnapshotInput si2{snap}; assert(si2.snapshot.position.value == 100);
    std::cout << "  timeline_snapshot_input_tests: ALL PASSED\n";
}
}
