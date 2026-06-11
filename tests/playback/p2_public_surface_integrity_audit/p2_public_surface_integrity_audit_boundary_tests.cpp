#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_audit/identity/p2_public_surface_integrity_audit_identity.h"
#include "playback/p2_public_surface_integrity_audit/anchor/p2_public_surface_integrity_view_audit_anchor.h"
#include "playback/p2_public_surface_integrity_audit/audit/playback_p2_public_surface_integrity_audit.h"
#include "playback/p2_public_surface_integrity_audit/outcome/p2_public_surface_integrity_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_integrity_audit;

void test_p2_public_surface_integrity_audit_boundary_cross_family() {
    P2PublicSurfaceIntegrityViewAuditAnchor anchor{};
    anchor.integrity_view_identity.view_id = kivo::playback::p2_public_surface_integrity_view::P2PublicSurfaceIntegrityViewId{123};
    assert(anchor.integrity_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceIntegrityAudit audit{
        .identity = P2PublicSurfaceIntegrityAuditIdentity{.audit_id = P2PublicSurfaceIntegrityAuditId{1}},
        .anchors = P2PublicSurfaceIntegrityAuditAnchorSet{.integrity_view_anchor = anchor},
        .classification = P2PublicSurfaceIntegrityAuditClassification{.kind = P2PublicSurfaceIntegrityAuditKind::SurfaceIntact, .scope = P2PublicSurfaceIntegrityAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.integrity_view_anchor.integrity_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceIntegrityAuditKind::SurfaceIntact);
    assert(audit.classification.scope == P2PublicSurfaceIntegrityAuditScope::AuditBoundary);
    P2PublicSurfaceIntegrityAuditOutcome outcome{.identity = P2PublicSurfaceIntegrityAuditIdentity{.audit_id = P2PublicSurfaceIntegrityAuditId{42}}, .status = P2PublicSurfaceIntegrityAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceIntegrityAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_integrity_audit_boundary_cross_family" << std::endl;
}
