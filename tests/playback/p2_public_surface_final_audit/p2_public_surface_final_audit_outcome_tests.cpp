#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_final_audit/outcome/p2_public_surface_final_audit_outcome.h"
#include "playback/p2_public_surface_final_audit/outcome/p2_public_surface_final_audit_rejection_reason.h"
#include "playback/p2_public_surface_final_audit/outcome/p2_public_surface_final_audit_defer_reason.h"

using namespace kivo::playback::p2_public_surface_final_audit;

void test_p2_public_surface_final_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditStatus::Deferred) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditRejectionReason::SourceAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditDeferReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditDeferReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceFinalAuditDeferReason::Unknown) == 2);
    P2PublicSurfaceFinalAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceFinalAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_final_audit_outcome_default_construction" << std::endl;
}
