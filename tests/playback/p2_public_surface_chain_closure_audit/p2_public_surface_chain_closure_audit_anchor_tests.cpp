#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_chain_closure_audit/anchor/p2_public_surface_delta_chain_closure_audit_anchor.h"
#include "playback/p2_public_surface_chain_closure_audit/anchor/p2_public_surface_chain_closure_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_chain_closure_audit;
using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_chain_closure_audit_anchor_default_construction() {
    P2PublicSurfaceDeltaChainClosureAuditAnchor anchor{};
    assert(anchor.delta_identity.delta_id.value == 0);
    anchor.delta_identity.delta_id = P2PublicSurfaceDeltaId{123};
    assert(anchor.delta_identity.delta_id.value == 123);
    P2PublicSurfaceChainClosureAuditAnchorSet anchor_set{};
    assert(anchor_set.delta_anchor.delta_identity.delta_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_chain_closure_audit_anchor_default_construction" << std::endl;
}
