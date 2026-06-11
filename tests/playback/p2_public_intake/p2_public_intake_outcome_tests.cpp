#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_intake/outcome/p2_public_intake_outcome.h"
#include "playback/p2_public_intake/outcome/p2_public_intake_rejection_reason.h"
#include "playback/p2_public_intake/outcome/p2_public_intake_drop_reason.h"

using namespace kivo::playback::p2_public_intake;

void test_p2_public_intake_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicIntakeStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicIntakeStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicIntakeStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicIntakeStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicIntakeRejectionReason::ClosureAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicIntakeRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicIntakeRejectionReason::IntakeIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicIntakeRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicIntakeDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicIntakeDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicIntakeDropReason::Unknown) == 2);
    P2PublicIntakeOutcome outcome{};
    assert(outcome.identity.intake_id.value == 0);
    assert(outcome.status == P2PublicIntakeStatus::Unknown);
    std::cout << "PASS: test_p2_public_intake_outcome_default_construction" << std::endl;
}
