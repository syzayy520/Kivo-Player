#pragma once
#include "timeline_result_report_kind.h"
#include "timeline_result_fidelity_policy.h"
#include "timeline_result_priority.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportPolicy {
    TimelineResultReportKind report_kind{TimelineResultReportKind::Unknown};
    TimelineResultFidelityPolicy fidelity_policy{TimelineResultFidelityPolicy::Unknown};
    TimelineResultPriority priority{TimelineResultPriority::Unknown};
};
}
