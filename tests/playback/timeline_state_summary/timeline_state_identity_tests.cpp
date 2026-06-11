#include <cassert>
#include <iostream>
#include "playback/timeline_state_summary/identity/timeline_state_summary_id.h"
#include "playback/timeline_state_summary/identity/timeline_state_summary_sequence_id.h"
#include "playback/timeline_state_summary/identity/timeline_state_summary_generation.h"
#include "playback/timeline_state_summary/identity/timeline_state_summary_identity.h"
namespace kivo::playback::timeline_state_summary {
void run_timeline_state_identity_tests() {
    TimelineStateSummaryId sid1; assert(sid1.value == 0); TimelineStateSummaryId sid2{42}; assert(sid2.value == 42);
    TimelineStateSummarySequenceId seq1; assert(seq1.value == 0); TimelineStateSummarySequenceId seq2{7}; assert(seq2.value == 7);
    TimelineStateSummaryGeneration g1; assert(g1.value == 0); TimelineStateSummaryGeneration g2{3}; assert(g2.value == 3);
    TimelineStateSummaryIdentity ident1;
    assert(ident1.summary_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineStateSummaryIdentity ident2{.summary_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.summary_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_state_identity_tests: ALL PASSED\n";
}
void run_timeline_state_source_tests();
void run_timeline_state_input_tests();
void run_timeline_state_policy_tests();
void run_timeline_state_summary_tests();
void run_timeline_state_outcome_tests();
}
int main() {
    using namespace kivo::playback::timeline_state_summary;
    run_timeline_state_identity_tests(); run_timeline_state_source_tests();
    run_timeline_state_input_tests(); run_timeline_state_policy_tests();
    run_timeline_state_summary_tests(); run_timeline_state_outcome_tests();
    std::cout << "  ALL timeline state summary tests PASSED\n"; return 0;
}
