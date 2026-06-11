#include <cassert>
#include <iostream>

#include "playback/timeline_public_response/outcome/timeline_public_response_outcome.h"
#include "playback/timeline_public_response/outcome/timeline_public_response_rejection_reason.h"
#include "playback/timeline_public_response/outcome/timeline_public_response_drop_reason.h"

using namespace kivo::playback::timeline_public_response;

void test_response_outcome_default_construction() {
    {
        assert(static_cast<uint8_t>(TimelinePublicResponseStatus::Recorded) == 0);
        assert(static_cast<uint8_t>(TimelinePublicResponseStatus::Rejected) == 1);
        assert(static_cast<uint8_t>(TimelinePublicResponseStatus::Dropped) == 2);
        assert(static_cast<uint8_t>(TimelinePublicResponseStatus::Unknown) == 3);
        std::cout << "PASS: test_response_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<uint8_t>(TimelinePublicResponseRejectionReason::QueryAnchorMissing) == 0);
        assert(static_cast<uint8_t>(TimelinePublicResponseRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<uint8_t>(TimelinePublicResponseRejectionReason::ResponseIdentityMissing) == 2);
        assert(static_cast<uint8_t>(TimelinePublicResponseRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_response_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<uint8_t>(TimelinePublicResponseDropReason::Superseded) == 0);
        assert(static_cast<uint8_t>(TimelinePublicResponseDropReason::LowerPriority) == 1);
        assert(static_cast<uint8_t>(TimelinePublicResponseDropReason::Unknown) == 2);
        std::cout << "PASS: test_response_drop_reason_enum_values" << std::endl;
    }

    TimelinePublicResponseOutcome outcome{};
    assert(outcome.identity.response_id.value == 0);
    assert(outcome.status == TimelinePublicResponseStatus::Unknown);

    TimelinePublicResponseOutcome outcome2{
        .identity = TimelinePublicResponseIdentity{
            .response_id = TimelinePublicResponseId{1}
        },
        .status = TimelinePublicResponseStatus::Recorded
    };
    assert(outcome2.identity.response_id.value == 1);
    assert(outcome2.status == TimelinePublicResponseStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_response_outcome_default_construction" << std::endl;
}

static void test_response_outcome_field_modification() {
    TimelinePublicResponseOutcome outcome{};
    outcome.identity.response_id = TimelinePublicResponseId{999};
    outcome.status = TimelinePublicResponseStatus::Rejected;

    assert(outcome.identity.response_id.value == 999);
    assert(outcome.status == TimelinePublicResponseStatus::Rejected);

    std::cout << "PASS: test_response_outcome_field_modification" << std::endl;
}
