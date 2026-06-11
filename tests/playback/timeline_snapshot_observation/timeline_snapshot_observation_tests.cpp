#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/observation/timeline_snapshot_candidate.h"
#include "playback/timeline_snapshot_observation/observation/observed_timeline_snapshot.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_observation_tests() {
    TimelineSnapshotObservationIdentity ident{.observation_id{1}, .sequence_id{2}, .generation{3}};
    TimelineSnapshotCandidate c1;
    assert(c1.identity.observation_id.value == 0); assert(c1.snapshot.session_id.value == 0);
    kivo::playback::orchestration::PlaybackTimelineSnapshot snap; snap.position.value = 200;
    TimelineSnapshotCandidate c2{ident, snap}; assert(c2.snapshot.position.value == 200);
    ObservedTimelineSnapshot o1;
    assert(o1.identity.observation_id.value == 0);
    ObservedTimelineSnapshot o2{ident, snap}; assert(o2.snapshot.position.value == 200);
    std::cout << "  timeline_snapshot_observation_tests: ALL PASSED\n";
}
}
