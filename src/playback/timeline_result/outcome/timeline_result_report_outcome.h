#pragma once
#include "../identity/timeline_result_report_identity.h"
#include "timeline_result_report_status.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportOutcome {
    TimelineResultReportIdentity identity{};
    TimelineResultReportStatus status{TimelineResultReportStatus::Unknown};
};
}
