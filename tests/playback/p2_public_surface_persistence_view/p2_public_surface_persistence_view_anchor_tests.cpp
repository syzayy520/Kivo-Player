#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_persistence_view/anchor/p2_public_surface_durability_persistence_view_anchor.h"
#include "playback/p2_public_surface_persistence_view/anchor/p2_public_surface_persistence_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_persistence_view;
using namespace kivo::playback::p2_public_surface_durability_audit;

void test_p2_public_surface_persistence_view_anchor_default_construction() {
    P2PublicSurfaceDurabilityPersistenceViewAnchor anchor{};
    assert(anchor.durability_identity.audit_id.value == 0);
    anchor.durability_identity.audit_id = P2PublicSurfaceDurabilityAuditId{123};
    assert(anchor.durability_identity.audit_id.value == 123);
    P2PublicSurfacePersistenceViewAnchorSet anchor_set{};
    assert(anchor_set.durability_anchor.durability_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_persistence_view_anchor_default_construction" << std::endl;
}
