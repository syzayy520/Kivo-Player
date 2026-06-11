#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_view/anchor/p2_public_surface_coherence_stability_view_anchor.h"
#include "playback/p2_public_surface_stability_view/anchor/p2_public_surface_stability_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_stability_view;
using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_stability_view_anchor_default_construction() {
    P2PublicSurfaceCoherenceStabilityViewAnchor anchor{};
    assert(anchor.coherence_view_identity.view_id.value == 0);
    anchor.coherence_view_identity.view_id = P2PublicSurfaceCoherenceViewId{123};
    assert(anchor.coherence_view_identity.view_id.value == 123);
    P2PublicSurfaceStabilityViewAnchorSet anchor_set{};
    assert(anchor_set.coherence_view_anchor.coherence_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_stability_view_anchor_default_construction" << std::endl;
}
