#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_confirmation_audit/outcome/p2_public_surface_confirmation_audit_outcome.h"
#include "playback/p2_public_surface_confirmation_audit/outcome/p2_public_surface_confirmation_audit_rejection_reason.h"
#include "playback/p2_public_surface_confirmation_audit/outcome/p2_public_surface_confirmation_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_confirmation_audit;

void test_p2_public_surface_confirmation_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditRejectionReason::ConfirmationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationAuditDropReason::Unknown) == 2);
    P2PublicSurfaceConfirmationAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceConfirmationAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_confirmation_audit_outcome_default_construction" << std::endl;
}
