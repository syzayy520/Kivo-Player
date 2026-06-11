#include <cassert>
#include <iostream>
#include "playback/timeline_request/identity/timeline_request_id.h"
#include "playback/timeline_request/identity/timeline_request_sequence_id.h"
#include "playback/timeline_request/identity/timeline_request_generation.h"
#include "playback/timeline_request/identity/timeline_request_identity.h"
namespace kivo::playback::timeline_request {
void run_timeline_request_identity_tests() {
    TimelineRequestId id1; assert(id1.value == 0); TimelineRequestId id2{42}; assert(id2.value == 42);
    TimelineRequestSequenceId sid1; assert(sid1.value == 0); TimelineRequestSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineRequestGeneration g1; assert(g1.value == 0); TimelineRequestGeneration g2{3}; assert(g2.value == 3);
    TimelineRequestIdentity ident1;
    assert(ident1.request_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineRequestIdentity ident2{.request_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.request_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_request_identity_tests: ALL PASSED\n";
}
void run_timeline_request_source_tests();
void run_timeline_request_target_tests();
void run_timeline_request_policy_tests();
void run_timeline_request_normalization_tests();
void run_timeline_request_outcome_tests();
}
int main() {
    using namespace kivo::playback::timeline_request;
    run_timeline_request_identity_tests(); run_timeline_request_source_tests();
    run_timeline_request_target_tests(); run_timeline_request_policy_tests();
    run_timeline_request_normalization_tests(); run_timeline_request_outcome_tests();
    std::cout << "  ALL timeline request tests PASSED\n"; return 0;
}
