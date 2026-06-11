#pragma once
#include "playback/timeline_result/report/timeline_result_report_record.h"
namespace kivo::playback::timeline_snapshot_observation {
struct TimelineResultReportRecordInput {
    kivo::playback::timeline_result::TimelineResultReportRecord report_record{};
};
}
