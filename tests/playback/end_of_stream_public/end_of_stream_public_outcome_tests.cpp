#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/end_of_stream_public/outcome/end_of_stream_public_outcome.h"
#include "playback/end_of_stream_public/outcome/end_of_stream_public_rejection_reason.h"
#include "playback/end_of_stream_public/outcome/end_of_stream_public_drop_reason.h"

using namespace kivo::playback::end_of_stream_public;

void test_end_of_stream_public_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(EndOfStreamPublicStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicRejectionReason::TrackTransitionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicRejectionReason::EndIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicDropReason::Unknown) == 2);
    EndOfStreamPublicOutcome outcome{};
    assert(outcome.identity.end_id.value == 0);
    assert(outcome.status == EndOfStreamPublicStatus::Unknown);
    std::cout << "PASS: test_end_of_stream_public_outcome_default_construction" << std::endl;
}
