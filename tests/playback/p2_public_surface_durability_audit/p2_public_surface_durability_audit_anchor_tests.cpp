#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_audit/anchor/p2_public_surface_durability_view_audit_anchor.h"
#include "playback/p2_public_surface_durability_audit/anchor/p2_public_surface_durability_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_durability_audit;
using namespace kivo::playback::p2_public_surface_durability_view;

void test_p2_public_surface_durability_audit_anchor_default_construction() {
    P2PublicSurfaceDurabilityViewAuditAnchor anchor{};
    assert(anchor.durability_view_identity.view_id.value == 0);
    anchor.durability_view_identity.view_id = P2PublicSurfaceDurabilityViewId{123};
    assert(anchor.durability_view_identity.view_id.value == 123);
    P2PublicSurfaceDurabilityAuditAnchorSet anchor_set{};
    assert(anchor_set.durability_view_anchor.durability_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_durability_audit_anchor_default_construction" << std::endl;
}
