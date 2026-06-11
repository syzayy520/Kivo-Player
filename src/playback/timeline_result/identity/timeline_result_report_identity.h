#pragma once
#include "timeline_result_report_id.h"
#include "timeline_result_report_sequence_id.h"
#include "timeline_result_report_generation.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportIdentity {
    TimelineResultReportId report_id{};
    TimelineResultReportSequenceId sequence_id{};
    TimelineResultReportGeneration generation{};
};
}
