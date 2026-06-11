#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_observation/anchor/p2_public_chain_audit_surface_observation_anchor.h"
#include "playback/p2_public_surface_observation/anchor/p2_public_surface_observation_anchor_set.h"

using namespace kivo::playback::p2_public_surface_observation;
using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_surface_observation_anchor_default_construction() {
    P2PublicChainAuditSurfaceObservationAnchor anchor{};
    assert(anchor.audit_identity.audit_id.value == 0);
    anchor.audit_identity.audit_id = P2PublicChainAuditId{123};
    assert(anchor.audit_identity.audit_id.value == 123);
    P2PublicSurfaceObservationAnchorSet anchor_set{};
    assert(anchor_set.audit_anchor.audit_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_observation_anchor_default_construction" << std::endl;
}
