#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_view/anchor/p2_public_surface_continuity_durability_view_anchor.h"
#include "playback/p2_public_surface_durability_view/anchor/p2_public_surface_durability_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_durability_view;
using namespace kivo::playback::p2_public_surface_continuity_view;

void test_p2_public_surface_durability_view_anchor_default_construction() {
    P2PublicSurfaceContinuityDurabilityViewAnchor anchor{};
    assert(anchor.continuity_view_identity.view_id.value == 0);
    anchor.continuity_view_identity.view_id = P2PublicSurfaceContinuityViewId{123};
    assert(anchor.continuity_view_identity.view_id.value == 123);
    P2PublicSurfaceDurabilityViewAnchorSet anchor_set{};
    assert(anchor_set.continuity_view_anchor.continuity_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_durability_view_anchor_default_construction" << std::endl;
}
