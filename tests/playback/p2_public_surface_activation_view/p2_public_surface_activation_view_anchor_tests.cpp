#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_view/anchor/p2_public_surface_eligibility_activation_view_anchor.h"
#include "playback/p2_public_surface_activation_view/anchor/p2_public_surface_activation_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_activation_view;
using namespace kivo::playback::p2_public_surface_eligibility_view;

void test_p2_public_surface_activation_view_anchor_default_construction() {
    P2PublicSurfaceEligibilityActivationViewAnchor anchor{};
    assert(anchor.eligibility_view_identity.view_id.value == 0);
    anchor.eligibility_view_identity.view_id = P2PublicSurfaceEligibilityViewId{123};
    assert(anchor.eligibility_view_identity.view_id.value == 123);
    P2PublicSurfaceActivationViewAnchorSet anchor_set{};
    assert(anchor_set.eligibility_view_anchor.eligibility_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_activation_view_anchor_default_construction" << std::endl;
}
