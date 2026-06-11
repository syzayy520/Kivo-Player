#include <cassert>
#include <iostream>

#include "playback/timeline_public_query_delta/outcome/timeline_public_query_delta_outcome.h"

using namespace kivo::playback::timeline_public_query_delta;

void test_timeline_public_query_delta_outcome_default_construction() {
    TimelinePublicQueryDeltaOutcome outcome{};
    assert(outcome.status == TimelinePublicQueryDeltaStatus::Pending);
    assert(outcome.defer_reason == TimelinePublicQueryDeltaDeferReason::None);
    assert(outcome.rejection_reason == TimelinePublicQueryDeltaRejectionReason::None);

    TimelinePublicQueryDeltaOutcome outcome2{
        .status = TimelinePublicQueryDeltaStatus::Rejected,
        .defer_reason = TimelinePublicQueryDeltaDeferReason::FinalAuditIdentityMissing,
        .rejection_reason = TimelinePublicQueryDeltaRejectionReason::FinalAuditMismatch
    };
    assert(outcome2.status == TimelinePublicQueryDeltaStatus::Rejected);
    assert(outcome2.defer_reason == TimelinePublicQueryDeltaDeferReason::FinalAuditIdentityMissing);
    assert(outcome2.rejection_reason == TimelinePublicQueryDeltaRejectionReason::FinalAuditMismatch);

    std::cout << "PASS: test_timeline_public_query_delta_outcome_default_construction" << std::endl;
}
