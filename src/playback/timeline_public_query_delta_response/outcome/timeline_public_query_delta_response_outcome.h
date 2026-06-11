#pragma once

#include "timeline_public_query_delta_response_status.h"
#include "timeline_public_query_delta_response_defer_reason.h"
#include "timeline_public_query_delta_response_rejection_reason.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseOutcome {
    TimelinePublicQueryDeltaResponseStatus status{TimelinePublicQueryDeltaResponseStatus::Pending};
    TimelinePublicQueryDeltaResponseDeferReason defer_reason{TimelinePublicQueryDeltaResponseDeferReason::None};
    TimelinePublicQueryDeltaResponseRejectionReason rejection_reason{TimelinePublicQueryDeltaResponseRejectionReason::None};
};

} // namespace kivo::playback::timeline_public_query_delta_response
