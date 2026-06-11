#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_activation_audit/outcome/p2_public_surface_activation_audit_outcome.h"
#include "playback/p2_public_surface_activation_audit/outcome/p2_public_surface_activation_audit_rejection_reason.h"
#include "playback/p2_public_surface_activation_audit/outcome/p2_public_surface_activation_audit_drop_reason.h"

using namespace kivo::playback::p2_public_surface_activation_audit;

void test_p2_public_surface_activation_audit_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditRejectionReason::ActivationAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditRejectionReason::AuditIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationAuditDropReason::Unknown) == 2);
    P2PublicSurfaceActivationAuditOutcome outcome{};
    assert(outcome.identity.audit_id.value == 0);
    assert(outcome.status == P2PublicSurfaceActivationAuditStatus::Unknown);
    std::cout << "PASS: test_p2_public_surface_activation_audit_outcome_default_construction" << std::endl;
}
