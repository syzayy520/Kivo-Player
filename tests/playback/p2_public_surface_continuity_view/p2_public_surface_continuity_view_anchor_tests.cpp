#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_continuity_view/anchor/p2_public_surface_stability_continuity_view_anchor.h"
#include "playback/p2_public_surface_continuity_view/anchor/p2_public_surface_continuity_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_continuity_view;
using namespace kivo::playback::p2_public_surface_stability_audit;

void test_p2_public_surface_continuity_view_anchor_default_construction() {
    P2PublicSurfaceStabilityContinuityViewAnchor anchor{};
    assert(anchor.stability_identity.audit_id.value == 0);
    anchor.stability_identity.audit_id = P2PublicSurfaceStabilityAuditId{123};
    assert(anchor.stability_identity.audit_id.value == 123);
    P2PublicSurfaceContinuityViewAnchorSet anchor_set{};
    assert(anchor_set.stability_anchor.stability_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_continuity_view_anchor_default_construction" << std::endl;
}
