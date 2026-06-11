#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_custody_view/identity/p2_public_surface_custody_view_identity.h"
#include "playback/p2_public_surface_custody_view/anchor/p2_public_surface_retention_custody_view_anchor.h"
#include "playback/p2_public_surface_custody_view/custody_view/playback_p2_public_surface_custody_view.h"
#include "playback/p2_public_surface_custody_view/outcome/p2_public_surface_custody_view_outcome.h"

using namespace kivo::playback::p2_public_surface_custody_view;

void test_p2_public_surface_custody_view_boundary_cross_family() {
    P2PublicSurfaceRetentionCustodyViewAnchor anchor{};
    anchor.retention_identity.audit_id = kivo::playback::p2_public_surface_retention_audit::P2PublicSurfaceRetentionAuditId{123};
    assert(anchor.retention_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceCustodyView view{
        .identity = P2PublicSurfaceCustodyViewIdentity{.view_id = P2PublicSurfaceCustodyViewId{1}},
        .anchors = P2PublicSurfaceCustodyViewAnchorSet{.retention_anchor = anchor},
        .classification = P2PublicSurfaceCustodyViewClassification{.kind = P2PublicSurfaceCustodyViewKind::SurfaceHeld, .scope = P2PublicSurfaceCustodyViewScope::CustodyBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.retention_anchor.retention_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceCustodyViewKind::SurfaceHeld);
    assert(view.classification.scope == P2PublicSurfaceCustodyViewScope::CustodyBoundary);
    P2PublicSurfaceCustodyViewOutcome outcome{.identity = P2PublicSurfaceCustodyViewIdentity{.view_id = P2PublicSurfaceCustodyViewId{42}}, .status = P2PublicSurfaceCustodyViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceCustodyViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_custody_view_boundary_cross_family" << std::endl;
}
