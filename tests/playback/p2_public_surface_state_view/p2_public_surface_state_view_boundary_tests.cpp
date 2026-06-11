#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_state_view/identity/p2_public_surface_state_view_identity.h"
#include "playback/p2_public_surface_state_view/anchor/p2_public_surface_chain_closure_state_view_anchor.h"
#include "playback/p2_public_surface_state_view/state_view/playback_p2_public_surface_state_view.h"
#include "playback/p2_public_surface_state_view/outcome/p2_public_surface_state_view_outcome.h"

using namespace kivo::playback::p2_public_surface_state_view;

void test_p2_public_surface_state_view_boundary_cross_family() {
    P2PublicSurfaceChainClosureStateViewAnchor anchor{};
    anchor.closure_identity.audit_id = kivo::playback::p2_public_surface_chain_closure_audit::P2PublicSurfaceChainClosureAuditId{123};
    assert(anchor.closure_identity.audit_id.value == 123);
    PlaybackP2PublicSurfaceStateView view{
        .identity = P2PublicSurfaceStateViewIdentity{.view_id = P2PublicSurfaceStateViewId{1}},
        .anchors = P2PublicSurfaceStateViewAnchorSet{.closure_anchor = anchor},
        .classification = P2PublicSurfaceStateViewClassification{.kind = P2PublicSurfaceStateViewKind::SurfaceState, .scope = P2PublicSurfaceStateViewScope::StateViewBoundary}
    };
    assert(view.identity.view_id.value == 1);
    assert(view.anchors.closure_anchor.closure_identity.audit_id.value == 123);
    assert(view.classification.kind == P2PublicSurfaceStateViewKind::SurfaceState);
    assert(view.classification.scope == P2PublicSurfaceStateViewScope::StateViewBoundary);
    P2PublicSurfaceStateViewOutcome outcome{.identity = P2PublicSurfaceStateViewIdentity{.view_id = P2PublicSurfaceStateViewId{42}}, .status = P2PublicSurfaceStateViewStatus::Recorded};
    assert(outcome.identity.view_id.value == 42);
    assert(outcome.status == P2PublicSurfaceStateViewStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_state_view_boundary_cross_family" << std::endl;
}
