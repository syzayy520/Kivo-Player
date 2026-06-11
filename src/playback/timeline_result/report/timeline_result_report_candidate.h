#pragma once
#include "../identity/timeline_result_report_identity.h"
#include "playback/orchestration/timeline/playback_timeline_result.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportCandidate {
    TimelineResultReportIdentity identity{};
    kivo::playback::orchestration::PlaybackTimelineResult result{};
};
}
