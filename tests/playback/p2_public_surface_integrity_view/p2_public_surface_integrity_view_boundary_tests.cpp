#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_view/identity/p2_public_surface_integrity_view_identity.h"
#include "playback/p2_public_surface_integrity_view/anchor/p2_public_surface_validation_integrity_view_anchor.h"
#include "playback/p2_public_surface_integrity_view/integrity_view/playback_p2_public_surface_integrity_view.h"
#include "playback/p2_public_surface_integrity_view/outcome/p2_public_surface_integrity_view_outcome.h"

using namespace kivo::playback::p2_public_surface_integrity_view;

void test_p2_public_surface_integrity_view_boundary_cross_family() {
    P2PublicSurfaceValidationIntegrityViewAnchor anchor{};
    anchor.validation_view_identity.view_id = kivo::playback::p2_public_surface_validation_view::P2PublicSurfaceValidationViewId{123};
    assert(anchor.validation_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceIntegrityView view{
        .identity = P2PublicSurfaceIntegrityViewIdentity{.view_id = P2PublicSurfaceIntegrityViewId{1}},
        .anchors = P2PublicSurfaceIntegrityViewAnchorSet{.validation_view_anchor = anchor},
        .classification = P2PublicSurfaceIntegrityViewClassification{.kind = P2PublicSurfaceIntegrityViewKind::SurfaceIntact, .scope = P2PublicSurfaceIntegrityViewScope::IntegrityBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.validation_view_anchor.validation_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceIntegrityViewKind::SurfaceIntact);
    assert(view.classification.scope == P2PublicSurfaceIntegrityViewScope::IntegrityBoundary);
    P2PublicSurfaceIntegrityViewOutcome outcome{.identity = P2PublicSurfaceIntegrityViewIdentity{.view_id = P2PublicSurfaceIntegrityViewId{42}}, .status = P2PublicSurfaceIntegrityViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceIntegrityViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_integrity_view_boundary_cross_family" << std::endl;
}
