#pragma once
#include "timeline_result_report_envelope.h"
#include "reported_timeline_result.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportRecord {
    TimelineResultReportEnvelope envelope{};
    ReportedTimelineResult reported_result{};
};
}
