#pragma once
#include "timeline_decision_source_kind.h"
#include "timeline_request_identity_source_ref.h"
#include "timeline_normalized_request_source_ref.h"
namespace kivo::playback::timeline_decision {
struct TimelineDecisionSource {
    TimelineDecisionSourceKind kind{TimelineDecisionSourceKind::Unknown};
    TimelineRequestIdentitySourceRef identity_source{};
    TimelineNormalizedRequestSourceRef normalized_source{};
};
}
