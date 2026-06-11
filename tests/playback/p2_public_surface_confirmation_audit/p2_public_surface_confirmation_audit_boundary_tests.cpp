#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_audit/identity/p2_public_surface_confirmation_audit_identity.h"
#include "playback/p2_public_surface_confirmation_audit/anchor/p2_public_surface_confirmation_view_audit_anchor.h"
#include "playback/p2_public_surface_confirmation_audit/audit/playback_p2_public_surface_confirmation_audit.h"
#include "playback/p2_public_surface_confirmation_audit/outcome/p2_public_surface_confirmation_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_confirmation_audit;

void test_p2_public_surface_confirmation_audit_boundary_cross_family() {
    P2PublicSurfaceConfirmationViewAuditAnchor anchor{};
    anchor.confirmation_view_identity.view_id = kivo::playback::p2_public_surface_confirmation_view::P2PublicSurfaceConfirmationViewId{123};
    assert(anchor.confirmation_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceConfirmationAudit audit{
        .identity = P2PublicSurfaceConfirmationAuditIdentity{.audit_id = P2PublicSurfaceConfirmationAuditId{1}},
        .anchors = P2PublicSurfaceConfirmationAuditAnchorSet{.confirmation_view_anchor = anchor},
        .classification = P2PublicSurfaceConfirmationAuditClassification{.kind = P2PublicSurfaceConfirmationAuditKind::SurfaceConfirmed, .scope = P2PublicSurfaceConfirmationAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.confirmation_view_anchor.confirmation_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceConfirmationAuditKind::SurfaceConfirmed);
    assert(audit.classification.scope == P2PublicSurfaceConfirmationAuditScope::AuditBoundary);
    P2PublicSurfaceConfirmationAuditOutcome outcome{.identity = P2PublicSurfaceConfirmationAuditIdentity{.audit_id = P2PublicSurfaceConfirmationAuditId{42}}, .status = P2PublicSurfaceConfirmationAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceConfirmationAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_confirmation_audit_boundary_cross_family" << std::endl;
}
