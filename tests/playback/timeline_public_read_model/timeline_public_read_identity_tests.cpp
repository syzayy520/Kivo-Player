#include <cassert>
#include <iostream>
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_id.h"
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_sequence_id.h"
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_generation.h"
#include "playback/timeline_public_read_model/identity/timeline_public_read_model_identity.h"
namespace kivo::playback::timeline_public_read_model {
void run_timeline_public_read_identity_tests() {
    TimelinePublicReadModelId id1; assert(id1.value == 0); TimelinePublicReadModelId id2{42}; assert(id2.value == 42);
    TimelinePublicReadModelSequenceId sid1; assert(sid1.value == 0); TimelinePublicReadModelSequenceId sid2{7}; assert(sid2.value == 7);
    TimelinePublicReadModelGeneration g1; assert(g1.value == 0); TimelinePublicReadModelGeneration g2{3}; assert(g2.value == 3);
    TimelinePublicReadModelIdentity ident1;
    assert(ident1.read_model_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelinePublicReadModelIdentity ident2{.read_model_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.read_model_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_public_read_identity_tests: ALL PASSED\n";
}
void run_timeline_public_read_anchor_tests();
void run_timeline_public_read_classification_tests();
void run_timeline_public_read_model_tests();
void run_timeline_public_read_outcome_tests();
void run_timeline_public_read_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_public_read_model;
    run_timeline_public_read_identity_tests(); run_timeline_public_read_anchor_tests();
    run_timeline_public_read_classification_tests(); run_timeline_public_read_model_tests();
    run_timeline_public_read_outcome_tests(); run_timeline_public_read_boundary_tests();
    std::cout << "  ALL timeline public read model tests PASSED\n"; return 0;
}
