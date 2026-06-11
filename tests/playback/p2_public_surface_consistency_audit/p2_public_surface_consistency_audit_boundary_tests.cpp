#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_consistency_audit/identity/p2_public_surface_consistency_audit_identity.h"
#include "playback/p2_public_surface_consistency_audit/anchor/p2_public_surface_progress_consistency_audit_anchor.h"
#include "playback/p2_public_surface_consistency_audit/audit/playback_p2_public_surface_consistency_audit.h"
#include "playback/p2_public_surface_consistency_audit/outcome/p2_public_surface_consistency_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_consistency_audit;

void test_p2_public_surface_consistency_audit_boundary_cross_family() {
    P2PublicSurfaceProgressConsistencyAuditAnchor anchor{};
    anchor.progress_view_identity.view_id = kivo::playback::p2_public_surface_progress_view::P2PublicSurfaceProgressViewId{123};
    assert(anchor.progress_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceConsistencyAudit audit{
        .identity = P2PublicSurfaceConsistencyAuditIdentity{.audit_id = P2PublicSurfaceConsistencyAuditId{1}},
        .anchors = P2PublicSurfaceConsistencyAuditAnchorSet{.progress_view_anchor = anchor},
        .classification = P2PublicSurfaceConsistencyAuditClassification{.kind = P2PublicSurfaceConsistencyAuditKind::SurfaceConsistent, .scope = P2PublicSurfaceConsistencyAuditScope::ConsistencyBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.progress_view_anchor.progress_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceConsistencyAuditKind::SurfaceConsistent);
    assert(audit.classification.scope == P2PublicSurfaceConsistencyAuditScope::ConsistencyBoundary);
    P2PublicSurfaceConsistencyAuditOutcome outcome{.identity = P2PublicSurfaceConsistencyAuditIdentity{.audit_id = P2PublicSurfaceConsistencyAuditId{42}}, .status = P2PublicSurfaceConsistencyAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceConsistencyAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_consistency_audit_boundary_cross_family" << std::endl;
}
