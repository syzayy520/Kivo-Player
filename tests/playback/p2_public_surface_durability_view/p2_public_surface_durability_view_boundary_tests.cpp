#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_view/identity/p2_public_surface_durability_view_identity.h"
#include "playback/p2_public_surface_durability_view/anchor/p2_public_surface_continuity_durability_view_anchor.h"
#include "playback/p2_public_surface_durability_view/durability_view/playback_p2_public_surface_durability_view.h"
#include "playback/p2_public_surface_durability_view/outcome/p2_public_surface_durability_view_outcome.h"

using namespace kivo::playback::p2_public_surface_durability_view;

void test_p2_public_surface_durability_view_boundary_cross_family() {
    P2PublicSurfaceContinuityDurabilityViewAnchor anchor{};
    anchor.continuity_view_identity.view_id = kivo::playback::p2_public_surface_continuity_view::P2PublicSurfaceContinuityViewId{123};
    assert(anchor.continuity_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceDurabilityView view{
        .identity = P2PublicSurfaceDurabilityViewIdentity{.view_id = P2PublicSurfaceDurabilityViewId{1}},
        .anchors = P2PublicSurfaceDurabilityViewAnchorSet{.continuity_view_anchor = anchor},
        .classification = P2PublicSurfaceDurabilityViewClassification{.kind = P2PublicSurfaceDurabilityViewKind::SurfaceDurable, .scope = P2PublicSurfaceDurabilityViewScope::DurabilityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.continuity_view_anchor.continuity_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceDurabilityViewKind::SurfaceDurable);
    assert(view.classification.scope == P2PublicSurfaceDurabilityViewScope::DurabilityBoundary);
    P2PublicSurfaceDurabilityViewOutcome outcome{.identity = P2PublicSurfaceDurabilityViewIdentity{.view_id = P2PublicSurfaceDurabilityViewId{42}}, .status = P2PublicSurfaceDurabilityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceDurabilityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_durability_view_boundary_cross_family" << std::endl;
}
