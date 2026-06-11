#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_audit/anchor/p2_public_surface_confirmation_view_audit_anchor.h"
#include "playback/p2_public_surface_confirmation_audit/anchor/p2_public_surface_confirmation_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_confirmation_audit;
using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_audit_anchor_default_construction() {
    P2PublicSurfaceConfirmationViewAuditAnchor anchor{};
    assert(anchor.confirmation_view_identity.view_id.value == 0);
    anchor.confirmation_view_identity.view_id = P2PublicSurfaceConfirmationViewId{123};
    assert(anchor.confirmation_view_identity.view_id.value == 123);
    P2PublicSurfaceConfirmationAuditAnchorSet anchor_set{};
    assert(anchor_set.confirmation_view_anchor.confirmation_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_confirmation_audit_anchor_default_construction" << std::endl;
}
