#pragma once
#include "../identity/timeline_result_report_identity.h"
#include "../source/timeline_result_source.h"
#include "../input/timeline_result_input.h"
#include "../policy/timeline_result_report_policy.h"
namespace kivo::playback::timeline_result {
struct TimelineResultReportEnvelope {
    TimelineResultReportIdentity identity{};
    TimelineResultSource source{};
    TimelineResultInput input{};
    TimelineResultReportPolicy policy{};
};
}
