#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_integrity_audit/outcome/p2_public_surface_integrity_audit_outcome.h"
#include "playback/p2_public_surface_integrity_audit/outcome/p2_public_surface_integrity_audit_rejection_reason.h"
#include "playback/p2_public_surface_integrity_audit/outcome/p2_public_surface_integrity_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_integrity_audit;

void test_p2_public_surface_integrity_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditRejectionReason::IntegrityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityAuditDropReason::Unknown) == 2);
    P2PublicSurfaceIntegrityAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceIntegrityAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_integrity_audit_outcome_default_construction" << std::endl;
}
