#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_state_view/anchor/p2_public_surface_chain_closure_state_view_anchor.h"
#include "playback/p2_public_surface_state_view/anchor/p2_public_surface_state_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_state_view;
using namespace kivo::playback::p2_public_surface_chain_closure_audit;

void test_p2_public_surface_state_view_anchor_default_construction() {
    P2PublicSurfaceChainClosureStateViewAnchor anchor{};
    assert(anchor.closure_identity.audit_id.value == 0);
    anchor.closure_identity.audit_id = P2PublicSurfaceChainClosureAuditId{123};
    assert(anchor.closure_identity.audit_id.value == 123);
    P2PublicSurfaceStateViewAnchorSet anchor_set{};
    assert(anchor_set.closure_anchor.closure_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_state_view_anchor_default_construction" << std::endl;
}
