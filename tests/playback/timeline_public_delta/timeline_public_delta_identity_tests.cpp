#include <cassert>
#include <iostream>
#include "playback/timeline_public_delta/identity/timeline_public_delta_id.h"
#include "playback/timeline_public_delta/identity/timeline_public_delta_sequence_id.h"
#include "playback/timeline_public_delta/identity/timeline_public_delta_generation.h"
#include "playback/timeline_public_delta/identity/timeline_public_delta_identity.h"
namespace kivo::playback::timeline_public_delta {
void run_timeline_public_delta_identity_tests() {
    TimelinePublicDeltaId id1; assert(id1.value == 0); TimelinePublicDeltaId id2{42}; assert(id2.value == 42);
    TimelinePublicDeltaSequenceId sid1; assert(sid1.value == 0); TimelinePublicDeltaSequenceId sid2{7}; assert(sid2.value == 7);
    TimelinePublicDeltaGeneration g1; assert(g1.value == 0); TimelinePublicDeltaGeneration g2{3}; assert(g2.value == 3);
    TimelinePublicDeltaIdentity ident1;
    assert(ident1.delta_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelinePublicDeltaIdentity ident2{.delta_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.delta_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_public_delta_identity_tests: ALL PASSED\n";
}
void run_timeline_public_delta_anchor_tests();
void run_timeline_public_delta_classification_tests();
void run_timeline_public_delta_delta_tests();
void run_timeline_public_delta_outcome_tests();
void run_timeline_public_delta_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_public_delta;
    run_timeline_public_delta_identity_tests(); run_timeline_public_delta_anchor_tests();
    run_timeline_public_delta_classification_tests(); run_timeline_public_delta_delta_tests();
    run_timeline_public_delta_outcome_tests(); run_timeline_public_delta_boundary_tests();
    std::cout << "  ALL timeline public delta tests PASSED\n"; return 0;
}
