#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/outcome/p1_public_surface_closure_audit_outcome.h"
#include "playback/p1_public_surface_closure_audit/outcome/p1_public_surface_closure_audit_rejection_reason.h"
#include "playback/p1_public_surface_closure_audit/outcome/p1_public_surface_closure_audit_drop_reason.h"

using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p1_public_surface_closure_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditRejectionReason::RecoveryAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P1PublicSurfaceClosureAuditDropReason::Unknown) == 2);
    P1PublicSurfaceClosureAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P1PublicSurfaceClosureAuditStatus::Unknown);
    std::cout << "PASS: test_p1_public_surface_closure_audit_outcome_default_construction" << std::endl;
}
