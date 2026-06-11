#pragma once

#include "timeline_public_query_delta_status.h"
#include "timeline_public_query_delta_defer_reason.h"
#include "timeline_public_query_delta_rejection_reason.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaOutcome {
    TimelinePublicQueryDeltaStatus status{TimelinePublicQueryDeltaStatus::Pending};
    TimelinePublicQueryDeltaDeferReason defer_reason{TimelinePublicQueryDeltaDeferReason::None};
    TimelinePublicQueryDeltaRejectionReason rejection_reason{TimelinePublicQueryDeltaRejectionReason::None};
};

} // namespace kivo::playback::timeline_public_query_delta
