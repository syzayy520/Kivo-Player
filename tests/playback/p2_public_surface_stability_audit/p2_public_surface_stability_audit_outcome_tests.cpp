#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_stability_audit/outcome/p2_public_surface_stability_audit_outcome.h"
#include "playback/p2_public_surface_stability_audit/outcome/p2_public_surface_stability_audit_rejection_reason.h"
#include "playback/p2_public_surface_stability_audit/outcome/p2_public_surface_stability_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_stability_audit;

void test_p2_public_surface_stability_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditRejectionReason::StabilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityAuditDropReason::Unknown) == 2);
    P2PublicSurfaceStabilityAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceStabilityAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_stability_audit_outcome_default_construction" << std::endl;
}
