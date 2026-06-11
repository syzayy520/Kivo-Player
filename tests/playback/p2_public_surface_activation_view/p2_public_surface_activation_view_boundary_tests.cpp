#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_view/identity/p2_public_surface_activation_view_identity.h"
#include "playback/p2_public_surface_activation_view/anchor/p2_public_surface_eligibility_activation_view_anchor.h"
#include "playback/p2_public_surface_activation_view/activation_view/playback_p2_public_surface_activation_view.h"
#include "playback/p2_public_surface_activation_view/outcome/p2_public_surface_activation_view_outcome.h"

using namespace kivo::playback::p2_public_surface_activation_view;

void test_p2_public_surface_activation_view_boundary_cross_family() {
    P2PublicSurfaceEligibilityActivationViewAnchor anchor{};
    anchor.eligibility_view_identity.view_id = kivo::playback::p2_public_surface_eligibility_view::P2PublicSurfaceEligibilityViewId{123};
    assert(anchor.eligibility_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceActivationView view{
        .identity = P2PublicSurfaceActivationViewIdentity{.view_id = P2PublicSurfaceActivationViewId{1}},
        .anchors = P2PublicSurfaceActivationViewAnchorSet{.eligibility_view_anchor = anchor},
        .classification = P2PublicSurfaceActivationViewClassification{.kind = P2PublicSurfaceActivationViewKind::SurfaceActive, .scope = P2PublicSurfaceActivationViewScope::ActivationBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.eligibility_view_anchor.eligibility_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceActivationViewKind::SurfaceActive);
    assert(view.classification.scope == P2PublicSurfaceActivationViewScope::ActivationBoundary);
    P2PublicSurfaceActivationViewOutcome outcome{.identity = P2PublicSurfaceActivationViewIdentity{.view_id = P2PublicSurfaceActivationViewId{42}}, .status = P2PublicSurfaceActivationViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceActivationViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_activation_view_boundary_cross_family" << std::endl;
}
