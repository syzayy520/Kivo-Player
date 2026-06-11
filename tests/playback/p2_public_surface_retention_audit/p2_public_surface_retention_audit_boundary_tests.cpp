#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_audit/identity/p2_public_surface_retention_audit_identity.h"
#include "playback/p2_public_surface_retention_audit/anchor/p2_public_surface_retention_view_audit_anchor.h"
#include "playback/p2_public_surface_retention_audit/audit/playback_p2_public_surface_retention_audit.h"
#include "playback/p2_public_surface_retention_audit/outcome/p2_public_surface_retention_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_retention_audit;

void test_p2_public_surface_retention_audit_boundary_cross_family() {
    P2PublicSurfaceRetentionViewAuditAnchor anchor{};
    anchor.retention_view_identity.view_id = kivo::playback::p2_public_surface_retention_view::P2PublicSurfaceRetentionViewId{123};
    assert(anchor.retention_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceRetentionAudit audit{
        .identity = P2PublicSurfaceRetentionAuditIdentity{.audit_id = P2PublicSurfaceRetentionAuditId{1}},
        .anchors = P2PublicSurfaceRetentionAuditAnchorSet{.retention_view_anchor = anchor},
        .classification = P2PublicSurfaceRetentionAuditClassification{.kind = P2PublicSurfaceRetentionAuditKind::SurfaceRetained, .scope = P2PublicSurfaceRetentionAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.retention_view_anchor.retention_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceRetentionAuditKind::SurfaceRetained);
    assert(audit.classification.scope == P2PublicSurfaceRetentionAuditScope::AuditBoundary);
    P2PublicSurfaceRetentionAuditOutcome outcome{.identity = P2PublicSurfaceRetentionAuditIdentity{.audit_id = P2PublicSurfaceRetentionAuditId{42}}, .status = P2PublicSurfaceRetentionAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceRetentionAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_retention_audit_boundary_cross_family" << std::endl;
}
