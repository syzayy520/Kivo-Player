#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_availability_view/anchor/p2_public_surface_consistency_availability_view_anchor.h"
#include "playback/p2_public_surface_availability_view/anchor/p2_public_surface_availability_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_availability_view;
using namespace kivo::playback::p2_public_surface_consistency_audit;

void test_p2_public_surface_availability_view_anchor_default_construction() {
    P2PublicSurfaceConsistencyAvailabilityViewAnchor anchor{};
    assert(anchor.consistency_identity.audit_id.value == 0);
    anchor.consistency_identity.audit_id = P2PublicSurfaceConsistencyAuditId{123};
    assert(anchor.consistency_identity.audit_id.value == 123);
    P2PublicSurfaceAvailabilityViewAnchorSet anchor_set{};
    assert(anchor_set.consistency_anchor.consistency_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_availability_view_anchor_default_construction" << std::endl;
}
