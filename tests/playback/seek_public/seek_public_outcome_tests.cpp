#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/seek_public/outcome/seek_public_outcome.h"
#include "playback/seek_public/outcome/seek_public_rejection_reason.h"
#include "playback/seek_public/outcome/seek_public_drop_reason.h"

using namespace kivo::playback::seek_public;

void test_seek_public_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(SeekPublicStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(SeekPublicStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(SeekPublicStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(SeekPublicStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(SeekPublicRejectionReason::StreamSelectionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(SeekPublicRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(SeekPublicRejectionReason::SeekIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(SeekPublicRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(SeekPublicDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(SeekPublicDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(SeekPublicDropReason::Unknown) == 2);
    SeekPublicOutcome outcome{};
    assert(outcome.identity.seek_id.value == 0);
    assert(outcome.status == SeekPublicStatus::Unknown);
    std::cout << "PASS: test_seek_public_outcome_default_construction" << std::endl;
}
