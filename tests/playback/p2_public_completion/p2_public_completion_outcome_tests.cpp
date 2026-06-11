#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_completion/outcome/p2_public_completion_outcome.h"
#include "playback/p2_public_completion/outcome/p2_public_completion_rejection_reason.h"
#include "playback/p2_public_completion/outcome/p2_public_completion_drop_reason.h"

using namespace kivo::playback::p2_public_completion;

void test_p2_public_completion_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicCompletionStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCompletionStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCompletionStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCompletionStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCompletionRejectionReason::ReadbackAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCompletionRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCompletionRejectionReason::CompletionIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCompletionRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCompletionDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCompletionDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCompletionDropReason::Unknown) == 2);
    P2PublicCompletionOutcome outcome{};
    assert(outcome.identity.completion_id.value == 0);
    assert(outcome.status == P2PublicCompletionStatus::Unknown);
    std::cout << "PASS: test_p2_public_completion_outcome_default_construction" << std::endl;
}
