#include <cassert>
#include <iostream>

#include "playback/timeline_public_query/outcome/timeline_public_query_outcome.h"
#include "playback/timeline_public_query/outcome/timeline_public_query_rejection_reason.h"
#include "playback/timeline_public_query/outcome/timeline_public_query_drop_reason.h"

using namespace kivo::playback::timeline_public_query;

void test_query_outcome_default_construction() {
    {
        assert(static_cast<uint8_t>(TimelinePublicQueryStatus::Recorded) == 0);
        assert(static_cast<uint8_t>(TimelinePublicQueryStatus::Rejected) == 1);
        assert(static_cast<uint8_t>(TimelinePublicQueryStatus::Dropped) == 2);
        assert(static_cast<uint8_t>(TimelinePublicQueryStatus::Unknown) == 3);
        std::cout << "PASS: test_query_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<uint8_t>(TimelinePublicQueryRejectionReason::DeltaAnchorMissing) == 0);
        assert(static_cast<uint8_t>(TimelinePublicQueryRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<uint8_t>(TimelinePublicQueryRejectionReason::QueryIdentityMissing) == 2);
        assert(static_cast<uint8_t>(TimelinePublicQueryRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_query_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<uint8_t>(TimelinePublicQueryDropReason::Superseded) == 0);
        assert(static_cast<uint8_t>(TimelinePublicQueryDropReason::LowerPriority) == 1);
        assert(static_cast<uint8_t>(TimelinePublicQueryDropReason::Unknown) == 2);
        std::cout << "PASS: test_query_drop_reason_enum_values" << std::endl;
    }

    TimelinePublicQueryOutcome outcome{};
    assert(outcome.identity.query_id.value == 0);
    assert(outcome.status == TimelinePublicQueryStatus::Unknown);

    TimelinePublicQueryOutcome outcome2{
        .identity = TimelinePublicQueryIdentity{
            .query_id = TimelinePublicQueryId{1}
        },
        .status = TimelinePublicQueryStatus::Recorded
    };
    assert(outcome2.identity.query_id.value == 1);
    assert(outcome2.status == TimelinePublicQueryStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_query_outcome_default_construction" << std::endl;
}

static void test_query_outcome_field_modification() {
    TimelinePublicQueryOutcome outcome{};
    outcome.identity.query_id = TimelinePublicQueryId{999};
    outcome.status = TimelinePublicQueryStatus::Rejected;

    assert(outcome.identity.query_id.value == 999);
    assert(outcome.status == TimelinePublicQueryStatus::Rejected);

    std::cout << "PASS: test_query_outcome_field_modification" << std::endl;
}
