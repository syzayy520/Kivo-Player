#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_durability_audit/outcome/p2_public_surface_durability_audit_outcome.h"
#include "playback/p2_public_surface_durability_audit/outcome/p2_public_surface_durability_audit_rejection_reason.h"
#include "playback/p2_public_surface_durability_audit/outcome/p2_public_surface_durability_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_durability_audit;

void test_p2_public_surface_durability_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditRejectionReason::DurabilityAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityAuditDropReason::Unknown) == 2);
    P2PublicSurfaceDurabilityAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceDurabilityAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_durability_audit_outcome_default_construction" << std::endl;
}
