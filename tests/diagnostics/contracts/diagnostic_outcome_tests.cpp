#include <cassert>
#include <iostream>
#include "diagnostics/contracts/outcome/diagnostic_submission_status.h"
#include "diagnostics/contracts/outcome/diagnostic_submission_result.h"
#include "diagnostics/contracts/outcome/diagnostic_drop_reason.h"
#include "diagnostics/contracts/outcome/diagnostic_failure_reason.h"

namespace kivo::playback::diagnostics {
void run_diagnostic_outcome_tests() {
    DiagnosticSubmissionStatus s1 = DiagnosticSubmissionStatus::Accepted;
    DiagnosticSubmissionStatus s2 = DiagnosticSubmissionStatus::Rejected;
    DiagnosticSubmissionStatus s3 = DiagnosticSubmissionStatus::Dropped;
    assert(s1 != s2); assert(s2 != s3);

    DiagnosticSubmissionResult result1;
    assert(result1.event_id.value == 0);
    assert(result1.status == DiagnosticSubmissionStatus::Unknown);
    DiagnosticSubmissionResult result2{.event_id{DiagnosticEventId{777}}, .status{DiagnosticSubmissionStatus::Accepted}};
    assert(result2.event_id.value == 777);
    assert(result2.status == DiagnosticSubmissionStatus::Accepted);

    DiagnosticDropReason d1 = DiagnosticDropReason::CapacityExceeded;
    DiagnosticDropReason d2 = DiagnosticDropReason::SeverityFiltered;
    DiagnosticDropReason d3 = DiagnosticDropReason::SamplingExcluded;
    assert(d1 != d2); assert(d2 != d3);

    DiagnosticFailureReason f1 = DiagnosticFailureReason::SourceInvalid;
    DiagnosticFailureReason f2 = DiagnosticFailureReason::EventInvalid;
    assert(f1 != f2);

    std::cout << "  diagnostic_outcome_tests: ALL PASSED\n";
}
}
