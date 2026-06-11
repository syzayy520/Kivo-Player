#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_retention_audit/outcome/p2_public_surface_retention_audit_outcome.h"
#include "playback/p2_public_surface_retention_audit/outcome/p2_public_surface_retention_audit_rejection_reason.h"
#include "playback/p2_public_surface_retention_audit/outcome/p2_public_surface_retention_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_retention_audit;

void test_p2_public_surface_retention_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditRejectionReason::RetentionAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionAuditDropReason::Unknown) == 2);
    P2PublicSurfaceRetentionAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceRetentionAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_retention_audit_outcome_default_construction" << std::endl;
}
