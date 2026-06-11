#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_audit/identity/p2_public_surface_readiness_audit_identity.h"
#include "playback/p2_public_surface_readiness_audit/anchor/p2_public_surface_readiness_view_audit_anchor.h"
#include "playback/p2_public_surface_readiness_audit/audit/playback_p2_public_surface_readiness_audit.h"
#include "playback/p2_public_surface_readiness_audit/outcome/p2_public_surface_readiness_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_readiness_audit;

void test_p2_public_surface_readiness_audit_boundary_cross_family() {
    P2PublicSurfaceReadinessViewAuditAnchor anchor{};
    anchor.readiness_view_identity.view_id = kivo::playback::p2_public_surface_readiness_view::P2PublicSurfaceReadinessViewId{123};
    assert(anchor.readiness_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceReadinessAudit audit{
        .identity = P2PublicSurfaceReadinessAuditIdentity{.audit_id = P2PublicSurfaceReadinessAuditId{1}},
        .anchors = P2PublicSurfaceReadinessAuditAnchorSet{.readiness_view_anchor = anchor},
        .classification = P2PublicSurfaceReadinessAuditClassification{.kind = P2PublicSurfaceReadinessAuditKind::SurfaceReady, .scope = P2PublicSurfaceReadinessAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.readiness_view_anchor.readiness_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceReadinessAuditKind::SurfaceReady);
    assert(audit.classification.scope == P2PublicSurfaceReadinessAuditScope::AuditBoundary);
    P2PublicSurfaceReadinessAuditOutcome outcome{.identity = P2PublicSurfaceReadinessAuditIdentity{.audit_id = P2PublicSurfaceReadinessAuditId{42}}, .status = P2PublicSurfaceReadinessAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceReadinessAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_readiness_audit_boundary_cross_family" << std::endl;
}
