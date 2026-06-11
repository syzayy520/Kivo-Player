#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_validation_view/anchor/p2_public_surface_confirmation_validation_view_anchor.h"
#include "playback/p2_public_surface_validation_view/anchor/p2_public_surface_validation_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_validation_view;
using namespace kivo::playback::p2_public_surface_confirmation_audit;

void test_p2_public_surface_validation_view_anchor_default_construction() {
    P2PublicSurfaceConfirmationValidationViewAnchor anchor{};
    assert(anchor.confirmation_identity.audit_id.value == 0);
    anchor.confirmation_identity.audit_id = P2PublicSurfaceConfirmationAuditId{123};
    assert(anchor.confirmation_identity.audit_id.value == 123);
    P2PublicSurfaceValidationViewAnchorSet anchor_set{};
    assert(anchor_set.confirmation_anchor.confirmation_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_validation_view_anchor_default_construction" << std::endl;
}
