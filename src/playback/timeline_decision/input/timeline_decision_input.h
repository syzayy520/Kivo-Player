#pragma once
#include "timeline_decision_input_kind.h"
#include "timeline_normalized_request_input.h"
#include "timeline_request_envelope_input.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionInput {
    TimelineDecisionInputKind kind{TimelineDecisionInputKind::Unknown};
    TimelineNormalizedRequestInput normalized_request{};
    TimelineRequestEnvelopeInput request_envelope{};
};
}
