#include <cassert>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/identity/p1_public_surface_closure_audit_identity.h"
#include "playback/p1_public_surface_closure_audit/anchor/public_error_recovery_closure_audit_anchor.h"
#include "playback/p1_public_surface_closure_audit/audit/playback_p1_public_surface_closure_audit.h"
#include "playback/p1_public_surface_closure_audit/outcome/p1_public_surface_closure_audit_outcome.h"

using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p1_public_surface_closure_audit_boundary_cross_family() {
    PublicErrorRecoveryClosureAuditAnchor anchor{};
    anchor.recovery_identity.recovery_id = kivo::playback::public_error_recovery::PublicErrorRecoveryId{123};
    assert(anchor.recovery_identity.recovery_id.value == 123);
    PlaybackP1PublicSurfaceClosureAudit audit{
        .identity = P1PublicSurfaceClosureAuditIdentity{.audit_id = P1PublicSurfaceClosureAuditId{1}},
        .anchors = P1PublicSurfaceClosureAuditAnchorSet{.recovery_anchor = anchor},
        .classification = P1PublicSurfaceClosureAuditClassification{.kind = P1PublicSurfaceClosureAuditKind::ChainClosed, .scope = P1PublicSurfaceClosureAuditScope::P1Chain}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.recovery_anchor.recovery_identity.recovery_id.value == 123);
    assert(audit.classification.kind == P1PublicSurfaceClosureAuditKind::ChainClosed);
    assert(audit.classification.scope == P1PublicSurfaceClosureAuditScope::P1Chain);
    P1PublicSurfaceClosureAuditOutcome outcome{.identity = P1PublicSurfaceClosureAuditIdentity{.audit_id = P1PublicSurfaceClosureAuditId{42}}, .status = P1PublicSurfaceClosureAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P1PublicSurfaceClosureAuditStatus::Recorded);
    std::cout << "PASS: test_p1_public_surface_closure_audit_boundary_cross_family" << std::endl;
}
