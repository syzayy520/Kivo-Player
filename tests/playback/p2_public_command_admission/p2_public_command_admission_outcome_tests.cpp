#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_command_admission/outcome/p2_public_command_admission_outcome.h"
#include "playback/p2_public_command_admission/outcome/p2_public_command_admission_rejection_reason.h"
#include "playback/p2_public_command_admission/outcome/p2_public_command_admission_drop_reason.h"

using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_command_admission_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionStatus::Admitted) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionStatus::Deferred) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionRejectionReason::IntakeAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionRejectionReason::AdmissionIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCommandAdmissionDropReason::Unknown) == 2);
    P2PublicCommandAdmissionOutcome outcome{};
    assert(outcome.identity.admission_id.value == 0);
    assert(outcome.status == P2PublicCommandAdmissionStatus::Unknown);
    std::cout << "PASS: test_p2_public_command_admission_outcome_default_construction" << std::endl;
}
