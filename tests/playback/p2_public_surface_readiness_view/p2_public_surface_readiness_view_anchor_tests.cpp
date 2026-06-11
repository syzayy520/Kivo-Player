#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_view/anchor/p2_public_surface_availability_readiness_view_anchor.h"
#include "playback/p2_public_surface_readiness_view/anchor/p2_public_surface_readiness_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_readiness_view;
using namespace kivo::playback::p2_public_surface_availability_view;

void test_p2_public_surface_readiness_view_anchor_default_construction() {
    P2PublicSurfaceAvailabilityReadinessViewAnchor anchor{};
    assert(anchor.availability_view_identity.view_id.value == 0);
    anchor.availability_view_identity.view_id = P2PublicSurfaceAvailabilityViewId{123};
    assert(anchor.availability_view_identity.view_id.value == 123);
    P2PublicSurfaceReadinessViewAnchorSet anchor_set{};
    assert(anchor_set.availability_view_anchor.availability_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_readiness_view_anchor_default_construction" << std::endl;
}
