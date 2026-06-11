#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_audit/anchor/p2_public_surface_activation_view_audit_anchor.h"
#include "playback/p2_public_surface_activation_audit/anchor/p2_public_surface_activation_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_activation_audit;
using namespace kivo::playback::p2_public_surface_activation_view;

void test_p2_public_surface_activation_audit_anchor_default_construction() {
    P2PublicSurfaceActivationViewAuditAnchor anchor{};
    assert(anchor.activation_view_identity.view_id.value == 0);
    anchor.activation_view_identity.view_id = P2PublicSurfaceActivationViewId{123};
    assert(anchor.activation_view_identity.view_id.value == 123);
    P2PublicSurfaceActivationAuditAnchorSet anchor_set{};
    assert(anchor_set.activation_view_anchor.activation_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_activation_audit_anchor_default_construction" << std::endl;
}
