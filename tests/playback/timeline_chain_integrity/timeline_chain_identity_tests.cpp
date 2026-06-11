#include <cassert>
#include <iostream>
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_id.h"
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_sequence_id.h"
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_generation.h"
#include "playback/timeline_chain_integrity/identity/timeline_chain_integrity_identity.h"
namespace kivo::playback::timeline_chain_integrity {
void run_timeline_chain_identity_tests() {
    TimelineChainIntegrityId iid1; assert(iid1.value == 0); TimelineChainIntegrityId iid2{42}; assert(iid2.value == 42);
    TimelineChainIntegritySequenceId sid1; assert(sid1.value == 0); TimelineChainIntegritySequenceId sid2{7}; assert(sid2.value == 7);
    TimelineChainIntegrityGeneration g1; assert(g1.value == 0); TimelineChainIntegrityGeneration g2{3}; assert(g2.value == 3);
    TimelineChainIntegrityIdentity ident1; assert(ident1.integrity_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineChainIntegrityIdentity ident2{.integrity_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.integrity_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_chain_identity_tests: ALL PASSED\n";
}
void run_timeline_chain_anchor_tests();
void run_timeline_chain_policy_tests();
void run_timeline_chain_integrity_tests();
void run_timeline_chain_outcome_tests();
void run_timeline_chain_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_chain_integrity;
    run_timeline_chain_identity_tests(); run_timeline_chain_anchor_tests();
    run_timeline_chain_policy_tests(); run_timeline_chain_integrity_tests();
    run_timeline_chain_outcome_tests(); run_timeline_chain_boundary_tests();
    std::cout << "  ALL timeline chain integrity tests PASSED\n"; return 0;
}
