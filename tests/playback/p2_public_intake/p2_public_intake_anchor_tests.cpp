#include <cassert>
#include <iostream>

#include "playback/p2_public_intake/anchor/p1_closure_intake_anchor.h"
#include "playback/p2_public_intake/anchor/p2_public_intake_anchor_set.h"

using namespace kivo::playback::p2_public_intake;
using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p2_public_intake_anchor_default_construction() {
    P1ClosureIntakeAnchor anchor{};
    assert(anchor.closure_identity.audit_id.value == 0);
    anchor.closure_identity.audit_id = P1PublicSurfaceClosureAuditId{123};
    assert(anchor.closure_identity.audit_id.value == 123);
    P2PublicIntakeAnchorSet anchor_set{};
    assert(anchor_set.closure_anchor.closure_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_intake_anchor_default_construction" << std::endl;
}
