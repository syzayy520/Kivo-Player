#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_readback/outcome/p2_public_readback_outcome.h"
#include "playback/p2_public_readback/outcome/p2_public_readback_rejection_reason.h"
#include "playback/p2_public_readback/outcome/p2_public_readback_drop_reason.h"

using namespace kivo::playback::p2_public_readback;

void test_p2_public_readback_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicReadbackStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicReadbackStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicReadbackStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicReadbackStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicReadbackRejectionReason::AdmissionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicReadbackRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicReadbackRejectionReason::ReadbackIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicReadbackRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicReadbackDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicReadbackDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicReadbackDropReason::Unknown) == 2);
    P2PublicReadbackOutcome outcome{};
    assert(outcome.identity.readback_id.value == 0);
    assert(outcome.status == P2PublicReadbackStatus::Unknown);
    std::cout << "PASS: test_p2_public_readback_outcome_default_construction" << std::endl;
}
