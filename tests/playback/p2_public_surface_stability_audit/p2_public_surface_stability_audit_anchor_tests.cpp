#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_audit/anchor/p2_public_surface_stability_view_audit_anchor.h"
#include "playback/p2_public_surface_stability_audit/anchor/p2_public_surface_stability_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_stability_audit;
using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_audit_anchor_default_construction() {
    P2PublicSurfaceStabilityViewAuditAnchor anchor{};
    assert(anchor.stability_view_identity.view_id.value == 0);
    anchor.stability_view_identity.view_id = P2PublicSurfaceStabilityViewId{123};
    assert(anchor.stability_view_identity.view_id.value == 123);
    P2PublicSurfaceStabilityAuditAnchorSet anchor_set{};
    assert(anchor_set.stability_view_anchor.stability_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_stability_audit_anchor_default_construction" << std::endl;
}
