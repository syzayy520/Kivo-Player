#pragma once
#include "timeline_state_input_kind.h"
#include "timeline_decision_route_identity_input.h"
#include "timeline_result_report_identity_input.h"
namespace kivo::playback::timeline_state_summary {
struct TimelineStateInput {
    TimelineStateInputKind kind{TimelineStateInputKind::Unknown};
    TimelineDecisionRouteIdentityInput decision_input{};
    TimelineResultReportIdentityInput result_input{};
};
}
