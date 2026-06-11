#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/session_public/outcome/playback_session_public_outcome.h"
#include "playback/session_public/outcome/playback_session_public_rejection_reason.h"
#include "playback/session_public/outcome/playback_session_public_drop_reason.h"

using namespace kivo::playback::session_public;

void test_session_public_outcome_default_construction() {
    {
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicStatus::Recorded) == 0);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicStatus::Rejected) == 1);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicStatus::Dropped) == 2);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicStatus::Unknown) == 3);
        std::cout << "PASS: test_session_public_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicRejectionReason::LifecyclePhaseAnchorMissing) == 0);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicRejectionReason::SessionIdentityMissing) == 2);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_session_public_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicDropReason::Superseded) == 0);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicDropReason::LowerPriority) == 1);
        assert(static_cast<std::uint8_t>(PlaybackSessionPublicDropReason::Unknown) == 2);
        std::cout << "PASS: test_session_public_drop_reason_enum_values" << std::endl;
    }

    PlaybackSessionPublicOutcome outcome{};
    assert(outcome.identity.session_id.value == 0);
    assert(outcome.status == PlaybackSessionPublicStatus::Unknown);

    PlaybackSessionPublicOutcome outcome2{
        .identity = PlaybackSessionPublicIdentity{
            .session_id = PlaybackSessionPublicId{1}
        },
        .status = PlaybackSessionPublicStatus::Recorded
    };
    assert(outcome2.identity.session_id.value == 1);
    assert(outcome2.status == PlaybackSessionPublicStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_session_public_outcome_default_construction" << std::endl;

    outcome.identity.session_id = PlaybackSessionPublicId{999};
    outcome.status = PlaybackSessionPublicStatus::Rejected;

    assert(outcome.identity.session_id.value == 999);
    assert(outcome.status == PlaybackSessionPublicStatus::Rejected);

    std::cout << "PASS: test_session_public_outcome_field_modification" << std::endl;
}
