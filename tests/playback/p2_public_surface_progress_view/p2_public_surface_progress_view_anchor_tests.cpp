#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_progress_view/anchor/p2_public_surface_state_progress_view_anchor.h"
#include "playback/p2_public_surface_progress_view/anchor/p2_public_surface_progress_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_progress_view;
using namespace kivo::playback::p2_public_surface_state_view;

void test_p2_public_surface_progress_view_anchor_default_construction() {
    P2PublicSurfaceStateProgressViewAnchor anchor{};
    assert(anchor.state_view_identity.view_id.value == 0);
    anchor.state_view_identity.view_id = P2PublicSurfaceStateViewId{123};
    assert(anchor.state_view_identity.view_id.value == 123);
    P2PublicSurfaceProgressViewAnchorSet anchor_set{};
    assert(anchor_set.state_view_anchor.state_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_progress_view_anchor_default_construction" << std::endl;
}
