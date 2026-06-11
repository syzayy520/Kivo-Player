#include <cassert>
#include <iostream>
#include "playback/timeline_result/outcome/timeline_result_report_status.h"
#include "playback/timeline_result/outcome/timeline_result_report_outcome.h"
#include "playback/timeline_result/outcome/timeline_result_rejection_reason.h"
#include "playback/timeline_result/outcome/timeline_result_drop_reason.h"
namespace kivo::playback::timeline_result {
void run_timeline_result_outcome_tests() {
    assert(static_cast<int>(TimelineResultReportStatus::Reported) != static_cast<int>(TimelineResultReportStatus::Rejected));
    assert(static_cast<int>(TimelineResultReportStatus::Dropped) != static_cast<int>(TimelineResultReportStatus::Unknown));
    assert(static_cast<int>(TimelineResultRejectionReason::InputInvalid) != static_cast<int>(TimelineResultRejectionReason::ResultUnavailable));
    assert(static_cast<int>(TimelineResultRejectionReason::ReportPolicyInvalid) != static_cast<int>(TimelineResultRejectionReason::Unknown));
    assert(static_cast<int>(TimelineResultDropReason::Superseded) != static_cast<int>(TimelineResultDropReason::PriorityOverridden));
    assert(static_cast<int>(TimelineResultDropReason::Unknown) != static_cast<int>(TimelineResultDropReason::Superseded));
    TimelineResultReportOutcome o1;
    assert(o1.status == TimelineResultReportStatus::Unknown);
    assert(o1.identity.report_id.value == 0);
    TimelineResultReportIdentity ident{.report_id{10}, .sequence_id{20}, .generation{30}};
    TimelineResultReportOutcome o2{ident, TimelineResultReportStatus::Reported};
    assert(o2.identity.report_id.value == 10);
    assert(o2.status == TimelineResultReportStatus::Reported);
    std::cout << "  timeline_result_outcome_tests: ALL PASSED\n";
}
}
