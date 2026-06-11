#include <cassert>
#include <iostream>
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_id.h"
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_sequence_id.h"
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_generation.h"
#include "playback/timeline_snapshot_observation/identity/timeline_snapshot_observation_identity.h"
namespace kivo::playback::timeline_snapshot_observation {
void run_timeline_snapshot_identity_tests() {
    TimelineSnapshotObservationId oid1; assert(oid1.value == 0); TimelineSnapshotObservationId oid2{42}; assert(oid2.value == 42);
    TimelineSnapshotObservationSequenceId sid1; assert(sid1.value == 0); TimelineSnapshotObservationSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineSnapshotObservationGeneration g1; assert(g1.value == 0); TimelineSnapshotObservationGeneration g2{3}; assert(g2.value == 3);
    TimelineSnapshotObservationIdentity ident1;
    assert(ident1.observation_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineSnapshotObservationIdentity ident2{.observation_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.observation_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_snapshot_identity_tests: ALL PASSED\n";
}
void run_timeline_snapshot_source_tests();
void run_timeline_snapshot_input_tests();
void run_timeline_snapshot_policy_tests();
void run_timeline_snapshot_observation_tests();
void run_timeline_snapshot_outcome_tests();
}
int main() {
    using namespace kivo::playback::timeline_snapshot_observation;
    run_timeline_snapshot_identity_tests(); run_timeline_snapshot_source_tests();
    run_timeline_snapshot_input_tests(); run_timeline_snapshot_policy_tests();
    run_timeline_snapshot_observation_tests(); run_timeline_snapshot_outcome_tests();
    std::cout << "  ALL timeline snapshot observation tests PASSED\n"; return 0;
}
