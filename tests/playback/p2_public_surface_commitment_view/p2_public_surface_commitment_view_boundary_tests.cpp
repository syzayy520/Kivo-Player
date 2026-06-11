#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_commitment_view/identity/p2_public_surface_commitment_view_identity.h"
#include "playback/p2_public_surface_commitment_view/anchor/p2_public_surface_activation_commitment_view_anchor.h"
#include "playback/p2_public_surface_commitment_view/commitment_view/playback_p2_public_surface_commitment_view.h"
#include "playback/p2_public_surface_commitment_view/outcome/p2_public_surface_commitment_view_outcome.h"

using namespace kivo::playback::p2_public_surface_commitment_view;

void test_p2_public_surface_commitment_view_boundary_cross_family() {
    P2PublicSurfaceActivationCommitmentViewAnchor anchor{};
    anchor.activation_identity.audit_id = kivo::playback::p2_public_surface_activation_audit::P2PublicSurfaceActivationAuditId{123};
    assert(anchor.activation_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceCommitmentView view{
        .identity = P2PublicSurfaceCommitmentViewIdentity{.view_id = P2PublicSurfaceCommitmentViewId{1}},
        .anchors = P2PublicSurfaceCommitmentViewAnchorSet{.activation_anchor = anchor},
        .classification = P2PublicSurfaceCommitmentViewClassification{.kind = P2PublicSurfaceCommitmentViewKind::SurfaceCommitted, .scope = P2PublicSurfaceCommitmentViewScope::CommitmentBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.activation_anchor.activation_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceCommitmentViewKind::SurfaceCommitted);
    assert(view.classification.scope == P2PublicSurfaceCommitmentViewScope::CommitmentBoundary);
    P2PublicSurfaceCommitmentViewOutcome outcome{.identity = P2PublicSurfaceCommitmentViewIdentity{.view_id = P2PublicSurfaceCommitmentViewId{42}}, .status = P2PublicSurfaceCommitmentViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceCommitmentViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_commitment_view_boundary_cross_family" << std::endl;
}
