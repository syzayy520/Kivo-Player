#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_view/anchor/p2_public_surface_persistence_retention_view_anchor.h"
#include "playback/p2_public_surface_retention_view/anchor/p2_public_surface_retention_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_retention_view;
using namespace kivo::playback::p2_public_surface_persistence_view;

void test_p2_public_surface_retention_view_anchor_default_construction() {
    P2PublicSurfacePersistenceRetentionViewAnchor anchor{};
    assert(anchor.persistence_view_identity.view_id.value == 0);
    anchor.persistence_view_identity.view_id = P2PublicSurfacePersistenceViewId{123};
    assert(anchor.persistence_view_identity.view_id.value == 123);
    P2PublicSurfaceRetentionViewAnchorSet anchor_set{};
    assert(anchor_set.persistence_view_anchor.persistence_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_retention_view_anchor_default_construction" << std::endl;
}
