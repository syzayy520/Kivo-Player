#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_view/identity/p2_public_surface_stability_view_identity.h"
#include "playback/p2_public_surface_stability_view/anchor/p2_public_surface_coherence_stability_view_anchor.h"
#include "playback/p2_public_surface_stability_view/stability_view/playback_p2_public_surface_stability_view.h"
#include "playback/p2_public_surface_stability_view/outcome/p2_public_surface_stability_view_outcome.h"

using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_view_boundary_cross_family() {
    P2PublicSurfaceCoherenceStabilityViewAnchor anchor{};
    anchor.coherence_view_identity.view_id = kivo::playback::p2_public_surface_coherence_view::P2PublicSurfaceCoherenceViewId{123};
    assert(anchor.coherence_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceStabilityView view{
        .identity = P2PublicSurfaceStabilityViewIdentity{.view_id = P2PublicSurfaceStabilityViewId{1}},
        .anchors = P2PublicSurfaceStabilityViewAnchorSet{.coherence_view_anchor = anchor},
        .classification = P2PublicSurfaceStabilityViewClassification{.kind = P2PublicSurfaceStabilityViewKind::SurfaceStable, .scope = P2PublicSurfaceStabilityViewScope::StabilityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.coherence_view_anchor.coherence_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceStabilityViewKind::SurfaceStable);
    assert(view.classification.scope == P2PublicSurfaceStabilityViewScope::StabilityBoundary);
    P2PublicSurfaceStabilityViewOutcome outcome{.identity = P2PublicSurfaceStabilityViewIdentity{.view_id = P2PublicSurfaceStabilityViewId{42}}, .status = P2PublicSurfaceStabilityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceStabilityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_stability_view_boundary_cross_family" << std::endl;
}
