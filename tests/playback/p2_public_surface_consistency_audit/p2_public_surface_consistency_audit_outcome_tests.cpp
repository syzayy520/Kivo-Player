#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_consistency_audit/outcome/p2_public_surface_consistency_audit_outcome.h"
#include "playback/p2_public_surface_consistency_audit/outcome/p2_public_surface_consistency_audit_rejection_reason.h"
#include "playback/p2_public_surface_consistency_audit/outcome/p2_public_surface_consistency_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_consistency_audit;

void test_p2_public_surface_consistency_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditRejectionReason::ProgressViewAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConsistencyAuditDropReason::Unknown) == 2);
    P2PublicSurfaceConsistencyAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceConsistencyAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_consistency_audit_outcome_default_construction" << std::endl;
}
