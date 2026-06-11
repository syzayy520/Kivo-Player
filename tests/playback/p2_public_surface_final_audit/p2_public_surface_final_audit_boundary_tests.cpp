#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_final_audit/identity/p2_public_surface_final_audit_identity.h"
#include "playback/p2_public_surface_final_audit/anchor/p2_public_surface_source_final_anchor.h"
#include "playback/p2_public_surface_final_audit/audit/playback_p2_public_surface_final_audit.h"
#include "playback/p2_public_surface_final_audit/outcome/p2_public_surface_final_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_final_audit;

void test_p2_public_surface_final_audit_boundary_cross_family() {
    P2PublicSurfaceSourceFinalAnchor anchor{};
    anchor.source_identity_token = 123;
    assert(anchor.source_identity_token == 123);
    PlaybackP2PublicSurfaceFinalAudit audit{
        .identity = P2PublicSurfaceFinalAuditIdentity{.audit_id = P2PublicSurfaceFinalAuditId{1}},
        .anchors = P2PublicSurfaceFinalAuditAnchorSet{.source_anchor = anchor},
        .classification = P2PublicSurfaceFinalAuditClassification{.kind = P2PublicSurfaceFinalAuditKind::SurfaceFinalized, .scope = P2PublicSurfaceFinalAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.source_anchor.source_identity_token == 123);
    assert(audit.classification.kind == P2PublicSurfaceFinalAuditKind::SurfaceFinalized);
    assert(audit.classification.scope == P2PublicSurfaceFinalAuditScope::AuditBoundary);
    P2PublicSurfaceFinalAuditOutcome outcome{.identity = P2PublicSurfaceFinalAuditIdentity{.audit_id = P2PublicSurfaceFinalAuditId{42}}, .status = P2PublicSurfaceFinalAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceFinalAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_final_audit_boundary_cross_family" << std::endl;
}
