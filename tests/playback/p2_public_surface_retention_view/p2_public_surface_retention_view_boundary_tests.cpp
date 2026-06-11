#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_view/identity/p2_public_surface_retention_view_identity.h"
#include "playback/p2_public_surface_retention_view/anchor/p2_public_surface_persistence_retention_view_anchor.h"
#include "playback/p2_public_surface_retention_view/retention_view/playback_p2_public_surface_retention_view.h"
#include "playback/p2_public_surface_retention_view/outcome/p2_public_surface_retention_view_outcome.h"

using namespace kivo::playback::p2_public_surface_retention_view;

void test_p2_public_surface_retention_view_boundary_cross_family() {
    P2PublicSurfacePersistenceRetentionViewAnchor anchor{};
    anchor.persistence_view_identity.view_id = kivo::playback::p2_public_surface_persistence_view::P2PublicSurfacePersistenceViewId{123};
    assert(anchor.persistence_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceRetentionView view{
        .identity = P2PublicSurfaceRetentionViewIdentity{.view_id = P2PublicSurfaceRetentionViewId{1}},
        .anchors = P2PublicSurfaceRetentionViewAnchorSet{.persistence_view_anchor = anchor},
        .classification = P2PublicSurfaceRetentionViewClassification{.kind = P2PublicSurfaceRetentionViewKind::SurfaceRetained, .scope = P2PublicSurfaceRetentionViewScope::RetentionBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.persistence_view_anchor.persistence_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceRetentionViewKind::SurfaceRetained);
    assert(view.classification.scope == P2PublicSurfaceRetentionViewScope::RetentionBoundary);
    P2PublicSurfaceRetentionViewOutcome outcome{.identity = P2PublicSurfaceRetentionViewIdentity{.view_id = P2PublicSurfaceRetentionViewId{42}}, .status = P2PublicSurfaceRetentionViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceRetentionViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_retention_view_boundary_cross_family" << std::endl;
}
