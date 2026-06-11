#include <cassert>
#include <iostream>
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_id.h"
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_sequence_id.h"
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_generation.h"
#include "playback/timeline_public_snapshot/identity/timeline_public_snapshot_identity.h"
namespace kivo::playback::timeline_public_snapshot {
void run_timeline_public_snapshot_identity_tests() {
    TimelinePublicSnapshotId id1; assert(id1.value == 0); TimelinePublicSnapshotId id2{42}; assert(id2.value == 42);
    TimelinePublicSnapshotSequenceId sid1; assert(sid1.value == 0); TimelinePublicSnapshotSequenceId sid2{7}; assert(sid2.value == 7);
    TimelinePublicSnapshotGeneration g1; assert(g1.value == 0); TimelinePublicSnapshotGeneration g2{3}; assert(g2.value == 3);
    TimelinePublicSnapshotIdentity ident1;
    assert(ident1.snapshot_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelinePublicSnapshotIdentity ident2{.snapshot_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.snapshot_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_public_snapshot_identity_tests: ALL PASSED\n";
}
void run_timeline_public_snapshot_anchor_tests();
void run_timeline_public_snapshot_classification_tests();
void run_timeline_public_snapshot_snapshot_tests();
void run_timeline_public_snapshot_outcome_tests();
void run_timeline_public_snapshot_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_public_snapshot;
    run_timeline_public_snapshot_identity_tests(); run_timeline_public_snapshot_anchor_tests();
    run_timeline_public_snapshot_classification_tests(); run_timeline_public_snapshot_snapshot_tests();
    run_timeline_public_snapshot_outcome_tests(); run_timeline_public_snapshot_boundary_tests();
    std::cout << "  ALL timeline public snapshot tests PASSED\n"; return 0;
}
