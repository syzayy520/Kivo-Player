#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_progress_view/identity/p2_public_surface_progress_view_identity.h"
#include "playback/p2_public_surface_progress_view/anchor/p2_public_surface_state_progress_view_anchor.h"
#include "playback/p2_public_surface_progress_view/progress_view/playback_p2_public_surface_progress_view.h"
#include "playback/p2_public_surface_progress_view/outcome/p2_public_surface_progress_view_outcome.h"

using namespace kivo::playback::p2_public_surface_progress_view;

void test_p2_public_surface_progress_view_boundary_cross_family() {
    P2PublicSurfaceStateProgressViewAnchor anchor{};
    anchor.state_view_identity.view_id = kivo::playback::p2_public_surface_state_view::P2PublicSurfaceStateViewId{123};
    assert(anchor.state_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceProgressView view{
        .identity = P2PublicSurfaceProgressViewIdentity{.view_id = P2PublicSurfaceProgressViewId{1}},
        .anchors = P2PublicSurfaceProgressViewAnchorSet{.state_view_anchor = anchor},
        .classification = P2PublicSurfaceProgressViewClassification{.kind = P2PublicSurfaceProgressViewKind::SurfaceProgress, .scope = P2PublicSurfaceProgressViewScope::ProgressViewBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.state_view_anchor.state_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceProgressViewKind::SurfaceProgress);
    assert(view.classification.scope == P2PublicSurfaceProgressViewScope::ProgressViewBoundary);
    P2PublicSurfaceProgressViewOutcome outcome{.identity = P2PublicSurfaceProgressViewIdentity{.view_id = P2PublicSurfaceProgressViewId{42}}, .status = P2PublicSurfaceProgressViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceProgressViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_progress_view_boundary_cross_family" << std::endl;
}
