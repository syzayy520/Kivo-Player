#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_preservation_view/anchor/p2_public_surface_custody_preservation_view_anchor.h"
#include "playback/p2_public_surface_preservation_view/anchor/p2_public_surface_preservation_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_preservation_view;
using namespace kivo::playback::p2_public_surface_custody_view;

void test_p2_public_surface_preservation_view_anchor_default_construction() {
    P2PublicSurfaceCustodyPreservationViewAnchor anchor{};
    assert(anchor.custody_view_identity.view_id.value == 0);
    anchor.custody_view_identity.view_id = P2PublicSurfaceCustodyViewId{123};
    assert(anchor.custody_view_identity.view_id.value == 123);
    P2PublicSurfacePreservationViewAnchorSet anchor_set{};
    assert(anchor_set.custody_view_anchor.custody_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_preservation_view_anchor_default_construction" << std::endl;
}
