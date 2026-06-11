#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_audit/anchor/p2_public_surface_readiness_view_audit_anchor.h"
#include "playback/p2_public_surface_readiness_audit/anchor/p2_public_surface_readiness_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_readiness_audit;
using namespace kivo::playback::p2_public_surface_readiness_view;

void test_p2_public_surface_readiness_audit_anchor_default_construction() {
    P2PublicSurfaceReadinessViewAuditAnchor anchor{};
    assert(anchor.readiness_view_identity.view_id.value == 0);
    anchor.readiness_view_identity.view_id = P2PublicSurfaceReadinessViewId{123};
    assert(anchor.readiness_view_identity.view_id.value == 123);
    P2PublicSurfaceReadinessAuditAnchorSet anchor_set{};
    assert(anchor_set.readiness_view_anchor.readiness_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_readiness_audit_anchor_default_construction" << std::endl;
}
