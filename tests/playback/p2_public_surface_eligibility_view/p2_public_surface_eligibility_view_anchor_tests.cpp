#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_eligibility_view/anchor/p2_public_surface_readiness_eligibility_view_anchor.h"
#include "playback/p2_public_surface_eligibility_view/anchor/p2_public_surface_eligibility_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_eligibility_view;
using namespace kivo::playback::p2_public_surface_readiness_audit;

void test_p2_public_surface_eligibility_view_anchor_default_construction() {
    P2PublicSurfaceReadinessEligibilityViewAnchor anchor{};
    assert(anchor.readiness_identity.audit_id.value == 0);
    anchor.readiness_identity.audit_id = P2PublicSurfaceReadinessAuditId{123};
    assert(anchor.readiness_identity.audit_id.value == 123);
    P2PublicSurfaceEligibilityViewAnchorSet anchor_set{};
    assert(anchor_set.readiness_anchor.readiness_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_eligibility_view_anchor_default_construction" << std::endl;
}
