#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_continuity_view/identity/p2_public_surface_continuity_view_identity.h"
#include "playback/p2_public_surface_continuity_view/anchor/p2_public_surface_stability_continuity_view_anchor.h"
#include "playback/p2_public_surface_continuity_view/continuity_view/playback_p2_public_surface_continuity_view.h"
#include "playback/p2_public_surface_continuity_view/outcome/p2_public_surface_continuity_view_outcome.h"

using namespace kivo::playback::p2_public_surface_continuity_view;

void test_p2_public_surface_continuity_view_boundary_cross_family() {
    P2PublicSurfaceStabilityContinuityViewAnchor anchor{};
    anchor.stability_identity.audit_id = kivo::playback::p2_public_surface_stability_audit::P2PublicSurfaceStabilityAuditId{123};
    assert(anchor.stability_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceContinuityView view{
        .identity = P2PublicSurfaceContinuityViewIdentity{.view_id = P2PublicSurfaceContinuityViewId{1}},
        .anchors = P2PublicSurfaceContinuityViewAnchorSet{.stability_anchor = anchor},
        .classification = P2PublicSurfaceContinuityViewClassification{.kind = P2PublicSurfaceContinuityViewKind::SurfaceContinuous, .scope = P2PublicSurfaceContinuityViewScope::ContinuityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.stability_anchor.stability_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceContinuityViewKind::SurfaceContinuous);
    assert(view.classification.scope == P2PublicSurfaceContinuityViewScope::ContinuityBoundary);
    P2PublicSurfaceContinuityViewOutcome outcome{.identity = P2PublicSurfaceContinuityViewIdentity{.view_id = P2PublicSurfaceContinuityViewId{42}}, .status = P2PublicSurfaceContinuityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceContinuityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_continuity_view_boundary_cross_family" << std::endl;
}
