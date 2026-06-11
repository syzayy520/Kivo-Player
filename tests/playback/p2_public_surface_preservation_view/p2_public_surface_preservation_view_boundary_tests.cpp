#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_preservation_view/identity/p2_public_surface_preservation_view_identity.h"
#include "playback/p2_public_surface_preservation_view/anchor/p2_public_surface_custody_preservation_view_anchor.h"
#include "playback/p2_public_surface_preservation_view/preservation_view/playback_p2_public_surface_preservation_view.h"
#include "playback/p2_public_surface_preservation_view/outcome/p2_public_surface_preservation_view_outcome.h"

using namespace kivo::playback::p2_public_surface_preservation_view;

void test_p2_public_surface_preservation_view_boundary_cross_family() {
    P2PublicSurfaceCustodyPreservationViewAnchor anchor{};
    anchor.custody_view_identity.view_id = kivo::playback::p2_public_surface_custody_view::P2PublicSurfaceCustodyViewId{123};
    assert(anchor.custody_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfacePreservationView view{
        .identity = P2PublicSurfacePreservationViewIdentity{.view_id = P2PublicSurfacePreservationViewId{1}},
        .anchors = P2PublicSurfacePreservationViewAnchorSet{.custody_view_anchor = anchor},
        .classification = P2PublicSurfacePreservationViewClassification{.kind = P2PublicSurfacePreservationViewKind::SurfacePreserved, .scope = P2PublicSurfacePreservationViewScope::PreservationBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.custody_view_anchor.custody_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfacePreservationViewKind::SurfacePreserved);
    assert(view.classification.scope == P2PublicSurfacePreservationViewScope::PreservationBoundary);
    P2PublicSurfacePreservationViewOutcome outcome{.identity = P2PublicSurfacePreservationViewIdentity{.view_id = P2PublicSurfacePreservationViewId{42}}, .status = P2PublicSurfacePreservationViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfacePreservationViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_preservation_view_boundary_cross_family" << std::endl;
}
