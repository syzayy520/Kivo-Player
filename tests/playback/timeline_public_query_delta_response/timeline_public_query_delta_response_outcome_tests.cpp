#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta_response/outcome/timeline_public_query_delta_response_outcome.h"

using namespace kivo::playback::timeline_public_query_delta_response;

void test_query_delta_response_outcome_default_construction() {
    TimelinePublicQueryDeltaResponseOutcome outcome{};
    assert(outcome.status == TimelinePublicQueryDeltaResponseStatus::Pending);
    assert(outcome.defer_reason == TimelinePublicQueryDeltaResponseDeferReason::None);
    assert(outcome.rejection_reason == TimelinePublicQueryDeltaResponseRejectionReason::None);

    TimelinePublicQueryDeltaResponseOutcome outcome2{
        .status = TimelinePublicQueryDeltaResponseStatus::Rejected,
        .defer_reason = TimelinePublicQueryDeltaResponseDeferReason::FinalAuditIdentityMissing,
        .rejection_reason = TimelinePublicQueryDeltaResponseRejectionReason::FinalAuditMismatch
    };
    assert(outcome2.status == TimelinePublicQueryDeltaResponseStatus::Rejected);
    assert(outcome2.defer_reason == TimelinePublicQueryDeltaResponseDeferReason::FinalAuditIdentityMissing);
    assert(outcome2.rejection_reason == TimelinePublicQueryDeltaResponseRejectionReason::FinalAuditMismatch);

    std::cout << "PASS: test_query_delta_response_outcome_default_construction" << std::endl;
}
