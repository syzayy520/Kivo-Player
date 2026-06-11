#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_audit/identity/p2_public_surface_durability_audit_identity.h"
#include "playback/p2_public_surface_durability_audit/anchor/p2_public_surface_durability_view_audit_anchor.h"
#include "playback/p2_public_surface_durability_audit/audit/playback_p2_public_surface_durability_audit.h"
#include "playback/p2_public_surface_durability_audit/outcome/p2_public_surface_durability_audit_outcome.h"

using namespace kivo::playback::p2_public_surface_durability_audit;

void test_p2_public_surface_durability_audit_boundary_cross_family() {
    P2PublicSurfaceDurabilityViewAuditAnchor anchor{};
    anchor.durability_view_identity.view_id = kivo::playback::p2_public_surface_durability_view::P2PublicSurfaceDurabilityViewId{123};
    assert(anchor.durability_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceDurabilityAudit audit{
        .identity = P2PublicSurfaceDurabilityAuditIdentity{.audit_id = P2PublicSurfaceDurabilityAuditId{1}},
        .anchors = P2PublicSurfaceDurabilityAuditAnchorSet{.durability_view_anchor = anchor},
        .classification = P2PublicSurfaceDurabilityAuditClassification{.kind = P2PublicSurfaceDurabilityAuditKind::SurfaceDurable, .scope = P2PublicSurfaceDurabilityAuditScope::AuditBoundary}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.durability_view_anchor.durability_view_identity.view_id.value == 123);
    assert(audit.classification.kind == P2PublicSurfaceDurabilityAuditKind::SurfaceDurable);
    assert(audit.classification.scope == P2PublicSurfaceDurabilityAuditScope::AuditBoundary);
    P2PublicSurfaceDurabilityAuditOutcome outcome{.identity = P2PublicSurfaceDurabilityAuditIdentity{.audit_id = P2PublicSurfaceDurabilityAuditId{42}}, .status = P2PublicSurfaceDurabilityAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicSurfaceDurabilityAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_durability_audit_boundary_cross_family" << std::endl;
}
