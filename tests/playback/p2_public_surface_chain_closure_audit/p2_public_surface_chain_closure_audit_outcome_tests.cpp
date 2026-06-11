#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_chain_closure_audit/outcome/p2_public_surface_chain_closure_audit_outcome.h"
#include "playback/p2_public_surface_chain_closure_audit/outcome/p2_public_surface_chain_closure_audit_rejection_reason.h"
#include "playback/p2_public_surface_chain_closure_audit/outcome/p2_public_surface_chain_closure_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_chain_closure_audit;

void test_p2_public_surface_chain_closure_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditRejectionReason::DeltaAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceChainClosureAuditDropReason::Unknown) == 2);
    P2PublicSurfaceChainClosureAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceChainClosureAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_chain_closure_audit_outcome_default_construction" << std::endl;
}
