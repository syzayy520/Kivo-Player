#include <cassert>
#include <iostream>
#include "playback/timeline_result/policy/timeline_result_report_kind.h"
#include "playback/timeline_result/policy/timeline_result_fidelity_policy.h"
#include "playback/timeline_result/policy/timeline_result_priority.h"
#include "playback/timeline_result/policy/timeline_result_report_policy.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_policy_tests() {
    assert(static_cast<int>(TimelineResultReportKind::RoutedResult) != static_cast<int>(TimelineResultReportKind::StateOnly));
    assert(static_cast<int>(TimelineResultReportKind::Unknown) != static_cast<int>(TimelineResultReportKind::RoutedResult));
    assert(static_cast<int>(TimelineResultFidelityPolicy::PreserveDecision) != static_cast<int>(TimelineResultFidelityPolicy::PreserveSession));
    assert(static_cast<int>(TimelineResultFidelityPolicy::Unknown) != static_cast<int>(TimelineResultFidelityPolicy::PreserveUnknown));
    assert(static_cast<int>(TimelineResultPriority::Low) != static_cast<int>(TimelineResultPriority::High));
    assert(static_cast<int>(TimelineResultPriority::Unknown) != static_cast<int>(TimelineResultPriority::Normal));
    TimelineResultReportPolicy p1;
    assert(p1.report_kind == TimelineResultReportKind::Unknown);
    assert(p1.fidelity_policy == TimelineResultFidelityPolicy::Unknown);
    assert(p1.priority == TimelineResultPriority::Unknown);
    TimelineResultReportPolicy p2{TimelineResultReportKind::RoutedResult, TimelineResultFidelityPolicy::PreserveDecision, TimelineResultPriority::High};
    assert(p2.report_kind == TimelineResultReportKind::RoutedResult);
    assert(p2.fidelity_policy == TimelineResultFidelityPolicy::PreserveDecision);
    assert(p2.priority == TimelineResultPriority::High);
    std::cout << "  timeline_result_policy_tests: ALL PASSED\n";
}
}
