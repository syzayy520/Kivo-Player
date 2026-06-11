#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_chain_audit/outcome/p2_public_chain_audit_outcome.h"
#include "playback/p2_public_chain_audit/outcome/p2_public_chain_audit_rejection_reason.h"
#include "playback/p2_public_chain_audit/outcome/p2_public_chain_audit_drop_reason.h"

using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_chain_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicChainAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditRejectionReason::CompletionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditDropReason::Unknown) == 2);
    P2PublicChainAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicChainAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_chain_audit_outcome_default_construction" << std::endl;
}
