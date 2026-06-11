#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_view/identity/p2_public_surface_readiness_view_identity.h"
#include "playback/p2_public_surface_readiness_view/anchor/p2_public_surface_availability_readiness_view_anchor.h"
#include "playback/p2_public_surface_readiness_view/readiness_view/playback_p2_public_surface_readiness_view.h"
#include "playback/p2_public_surface_readiness_view/outcome/p2_public_surface_readiness_view_outcome.h"

using namespace kivo::playback::p2_public_surface_readiness_view;

void test_p2_public_surface_readiness_view_boundary_cross_family() {
    P2PublicSurfaceAvailabilityReadinessViewAnchor anchor{};
    anchor.availability_view_identity.view_id = kivo::playback::p2_public_surface_availability_view::P2PublicSurfaceAvailabilityViewId{123};
    assert(anchor.availability_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceReadinessView view{
        .identity = P2PublicSurfaceReadinessViewIdentity{.view_id = P2PublicSurfaceReadinessViewId{1}},
        .anchors = P2PublicSurfaceReadinessViewAnchorSet{.availability_view_anchor = anchor},
        .classification = P2PublicSurfaceReadinessViewClassification{.kind = P2PublicSurfaceReadinessViewKind::SurfaceReady, .scope = P2PublicSurfaceReadinessViewScope::ReadinessBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.availability_view_anchor.availability_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceReadinessViewKind::SurfaceReady);
    assert(view.classification.scope == P2PublicSurfaceReadinessViewScope::ReadinessBoundary);
    P2PublicSurfaceReadinessViewOutcome outcome{.identity = P2PublicSurfaceReadinessViewIdentity{.view_id = P2PublicSurfaceReadinessViewId{42}}, .status = P2PublicSurfaceReadinessViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceReadinessViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_readiness_view_boundary_cross_family" << std::endl;
}
