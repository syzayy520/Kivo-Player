#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/identity/p2_public_surface_confirmation_view_identity.h"
#include "playback/p2_public_surface_confirmation_view/anchor/p2_public_surface_commitment_confirmation_view_anchor.h"
#include "playback/p2_public_surface_confirmation_view/confirmation_view/playback_p2_public_surface_confirmation_view.h"
#include "playback/p2_public_surface_confirmation_view/outcome/p2_public_surface_confirmation_view_outcome.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_view_boundary_cross_family() {
    P2PublicSurfaceCommitmentConfirmationViewAnchor anchor{};
    anchor.commitment_view_identity.view_id = kivo::playback::p2_public_surface_commitment_view::P2PublicSurfaceCommitmentViewId{123};
    assert(anchor.commitment_view_identity.view_id.value == 123);
    PlaybackP2PublicSurfaceConfirmationView view{
        .identity = P2PublicSurfaceConfirmationViewIdentity{.view_id = P2PublicSurfaceConfirmationViewId{1}},
        .anchors = P2PublicSurfaceConfirmationViewAnchorSet{.commitment_view_anchor = anchor},
        .classification = P2PublicSurfaceConfirmationViewClassification{.kind = P2PublicSurfaceConfirmationViewKind::SurfaceConfirmed, .scope = P2PublicSurfaceConfirmationViewScope::ConfirmationBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.commitment_view_anchor.commitment_view_identity.view_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceConfirmationViewKind::SurfaceConfirmed);
    assert(view.classification.scope == P2PublicSurfaceConfirmationViewScope::ConfirmationBoundary);
    P2PublicSurfaceConfirmationViewOutcome outcome{.identity = P2PublicSurfaceConfirmationViewIdentity{.view_id = P2PublicSurfaceConfirmationViewId{42}}, .status = P2PublicSurfaceConfirmationViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceConfirmationViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_confirmation_view_boundary_cross_family" << std::endl;
}
