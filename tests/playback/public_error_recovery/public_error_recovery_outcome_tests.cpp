#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/public_error_recovery/outcome/public_error_recovery_outcome.h"
#include "playback/public_error_recovery/outcome/public_error_recovery_rejection_reason.h"
#include "playback/public_error_recovery/outcome/public_error_recovery_drop_reason.h"

using namespace kivo::playback::public_error_recovery;

void test_public_error_recovery_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryRejectionReason::EndOfStreamAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryRejectionReason::RecoveryIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(PublicErrorRecoveryDropReason::Unknown) == 2);
    PublicErrorRecoveryOutcome outcome{};
    assert(outcome.identity.recovery_id.value == 0);
    assert(outcome.status == PublicErrorRecoveryStatus::Unknown);
    std::cout << "PASS: test_public_error_recovery_outcome_default_construction" << std::endl;
}
