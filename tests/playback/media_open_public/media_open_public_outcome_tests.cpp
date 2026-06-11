#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/media_open_public/outcome/media_open_public_outcome.h"
#include "playback/media_open_public/outcome/media_open_public_rejection_reason.h"
#include "playback/media_open_public/outcome/media_open_public_drop_reason.h"

using namespace kivo::playback::media_open_public;

void test_media_open_public_outcome_default_construction() {
    {
        assert(static_cast<std::uint8_t>(MediaOpenPublicStatus::Recorded) == 0);
        assert(static_cast<std::uint8_t>(MediaOpenPublicStatus::Rejected) == 1);
        assert(static_cast<std::uint8_t>(MediaOpenPublicStatus::Dropped) == 2);
        assert(static_cast<std::uint8_t>(MediaOpenPublicStatus::Unknown) == 3);
        std::cout << "PASS: test_media_open_public_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(MediaOpenPublicRejectionReason::SessionAnchorMissing) == 0);
        assert(static_cast<std::uint8_t>(MediaOpenPublicRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<std::uint8_t>(MediaOpenPublicRejectionReason::OpenIdentityMissing) == 2);
        assert(static_cast<std::uint8_t>(MediaOpenPublicRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_media_open_public_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(MediaOpenPublicDropReason::Superseded) == 0);
        assert(static_cast<std::uint8_t>(MediaOpenPublicDropReason::LowerPriority) == 1);
        assert(static_cast<std::uint8_t>(MediaOpenPublicDropReason::Unknown) == 2);
        std::cout << "PASS: test_media_open_public_drop_reason_enum_values" << std::endl;
    }

    MediaOpenPublicOutcome outcome{};
    assert(outcome.identity.open_id.value == 0);
    assert(outcome.status == MediaOpenPublicStatus::Unknown);

    MediaOpenPublicOutcome outcome2{
        .identity = MediaOpenPublicIdentity{
            .open_id = MediaOpenPublicId{1}
        },
        .status = MediaOpenPublicStatus::Recorded
    };
    assert(outcome2.identity.open_id.value == 1);
    assert(outcome2.status == MediaOpenPublicStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_media_open_public_outcome_default_construction" << std::endl;

    outcome.identity.open_id = MediaOpenPublicId{999};
    outcome.status = MediaOpenPublicStatus::Rejected;

    assert(outcome.identity.open_id.value == 999);
    assert(outcome.status == MediaOpenPublicStatus::Rejected);

    std::cout << "PASS: test_media_open_public_outcome_field_modification" << std::endl;
}
