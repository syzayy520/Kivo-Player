#include <cassert>
#include <iostream>
#include "playback/timeline_result/identity/timeline_result_report_id.h"
#include "playback/timeline_result/identity/timeline_result_report_sequence_id.h"
#include "playback/timeline_result/identity/timeline_result_report_generation.h"
#include "playback/timeline_result/identity/timeline_result_report_identity.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_identity_tests() {
    TimelineResultReportId rid1; assert(rid1.value == 0); TimelineResultReportId rid2{42}; assert(rid2.value == 42);
    TimelineResultReportSequenceId sid1; assert(sid1.value == 0); TimelineResultReportSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineResultReportGeneration g1; assert(g1.value == 0); TimelineResultReportGeneration g2{3}; assert(g2.value == 3);
    TimelineResultReportIdentity ident1;
    assert(ident1.report_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineResultReportIdentity ident2{.report_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.report_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_result_identity_tests: ALL PASSED\n";
}
void run_timeline_result_source_tests();
void run_timeline_result_input_tests();
void run_timeline_result_policy_tests();
void run_timeline_result_report_tests();
void run_timeline_result_outcome_tests();
}
int main() {
    using namespace kivo::playback::timeline_result;
    run_timeline_result_identity_tests(); run_timeline_result_source_tests();
    run_timeline_result_input_tests(); run_timeline_result_policy_tests();
    run_timeline_result_report_tests(); run_timeline_result_outcome_tests();
    std::cout << "  ALL timeline result tests PASSED\n"; return 0;
}
