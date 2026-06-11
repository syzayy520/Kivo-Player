#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/buffering_public/outcome/buffering_public_outcome.h"
#include "playback/buffering_public/outcome/buffering_public_rejection_reason.h"
#include "playback/buffering_public/outcome/buffering_public_drop_reason.h"

using namespace kivo::playback::buffering_public;

void test_buffering_public_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(BufferingPublicStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(BufferingPublicStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(BufferingPublicStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(BufferingPublicStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(BufferingPublicRejectionReason::SeekAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(BufferingPublicRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(BufferingPublicRejectionReason::BufferingIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(BufferingPublicRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(BufferingPublicDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(BufferingPublicDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(BufferingPublicDropReason::Unknown) == 2);
    BufferingPublicOutcome outcome{};
    assert(outcome.identity.buffering_id.value == 0);
    assert(outcome.status == BufferingPublicStatus::Unknown);
    std::cout << "PASS: test_buffering_public_outcome_default_construction" << std::endl;
}
