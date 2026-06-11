#pragma once
#include "playback/timeline_result/report/reported_timeline_result.h"
namespace kivo::playback::timeline_snapshot_observation {
struct ReportedTimelineResultSourceRef {
    kivo::playback::timeline_result::ReportedTimelineResult reported_result{};
};
}
