#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_audit/identity/p2_public_surface_stability_audit_identity.h"
#include "playback/p2_public_surface_stability_audit/anchor/p2_public_surface_stability_view_audit_anchor.h"
#include "playback/p2_public_surface_stability_audit/audit/playback_p2_public_surface_stability_audit.h"
#include "playback/p2_public_surface_stability_audit/outcome/p2_public_surface_stability_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_stability_audit;

void test_p2_public_surface_stability_audit_boundary_cross_family() {
    P2PublicSurfaceStabilityViewAuditAnchor anchor{};
    anchor.stability_view_identity.view_id = kivo::playback::p2_public_surface_stability_view::P2PublicSurfaceStabilityViewId{123};
    assert(anchor.stability_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceStabilityAudit audit{
        .identity = P2PublicSurfaceStabilityAuditIdentity{.audit_id = P2PublicSurfaceStabilityAuditId{1}},
        .anchors = P2PublicSurfaceStabilityAuditAnchorSet{.stability_view_anchor = anchor},
        .classification = P2PublicSurfaceStabilityAuditClassification{.kind = P2PublicSurfaceStabilityAuditKind::SurfaceStable, .scope = P2PublicSurfaceStabilityAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.stability_view_anchor.stability_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceStabilityAuditKind::SurfaceStable);
    assert(audit.classification.scope == P2PublicSurfaceStabilityAuditScope::AuditBoundary);
    P2PublicSurfaceStabilityAuditOutcome outcome{.identity = P2PublicSurfaceStabilityAuditIdentity{.audit_id = P2PublicSurfaceStabilityAuditId{42}}, .status = P2PublicSurfaceStabilityAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceStabilityAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_stability_audit_boundary_cross_family" << std::endl;
}
