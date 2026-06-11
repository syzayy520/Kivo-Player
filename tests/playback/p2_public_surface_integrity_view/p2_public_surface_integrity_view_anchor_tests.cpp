#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_view/anchor/p2_public_surface_validation_integrity_view_anchor.h"
#include "playback/p2_public_surface_integrity_view/anchor/p2_public_surface_integrity_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_integrity_view;
using namespace kivo::playback::p2_public_surface_validation_view;

void test_p2_public_surface_integrity_view_anchor_default_construction() {
    P2PublicSurfaceValidationIntegrityViewAnchor anchor{};
    assert(anchor.validation_view_identity.view_id.value == 0);
    anchor.validation_view_identity.view_id = P2PublicSurfaceValidationViewId{123};
    assert(anchor.validation_view_identity.view_id.value == 123);
    P2PublicSurfaceIntegrityViewAnchorSet anchor_set{};
    assert(anchor_set.validation_view_anchor.validation_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_integrity_view_anchor_default_construction" << std::endl;
}
