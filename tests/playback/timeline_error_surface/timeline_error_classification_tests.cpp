#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/classification/timeline_error_category.h"
#include "playback/timeline_error_surface/classification/timeline_error_severity.h"
#include "playback/timeline_error_surface/classification/timeline_error_recoverability.h"
#include "playback/timeline_error_surface/classification/timeline_error_phase.h"
#include "playback/timeline_error_surface/classification/timeline_error_classification.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_classification_tests() {
    assert(static_cast<int>(TimelineErrorCategory::Request) != static_cast<int>(TimelineErrorCategory::Unknown));
    assert(static_cast<int>(TimelineErrorSeverity::Fatal) != static_cast<int>(TimelineErrorSeverity::Unknown));
    assert(static_cast<int>(TimelineErrorRecoverability::Recoverable) != static_cast<int>(TimelineErrorRecoverability::Unknown));
    assert(static_cast<int>(TimelineErrorPhase::BeforeDecision) != static_cast<int>(TimelineErrorPhase::Unknown));
    TimelineErrorClassification c1;
    assert(c1.category == TimelineErrorCategory::Unknown);
    assert(c1.severity == TimelineErrorSeverity::Unknown);
    assert(c1.recoverability == TimelineErrorRecoverability::Unknown);
    assert(c1.phase == TimelineErrorPhase::Unknown);
    TimelineErrorClassification c2{TimelineErrorCategory::Result, TimelineErrorSeverity::Warning, TimelineErrorRecoverability::Recoverable, TimelineErrorPhase::AfterResult};
    assert(c2.category == TimelineErrorCategory::Result);
    assert(c2.severity == TimelineErrorSeverity::Warning);
    std::cout << "  timeline_error_classification_tests: ALL PASSED\n";
}
}
