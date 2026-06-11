#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_readiness_audit/outcome/p2_public_surface_readiness_audit_outcome.h"
#include "playback/p2_public_surface_readiness_audit/outcome/p2_public_surface_readiness_audit_rejection_reason.h"
#include "playback/p2_public_surface_readiness_audit/outcome/p2_public_surface_readiness_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_readiness_audit;

void test_p2_public_surface_readiness_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditRejectionReason::ReadinessAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessAuditDropReason::Unknown) == 2);
    P2PublicSurfaceReadinessAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceReadinessAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_readiness_audit_outcome_default_construction" << std::endl;
}
