#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_audit/anchor/p2_public_surface_retention_view_audit_anchor.h"
#include "playback/p2_public_surface_retention_audit/anchor/p2_public_surface_retention_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_retention_audit;
using namespace kivo::playback::p2_public_surface_retention_view;

void test_p2_public_surface_retention_audit_anchor_default_construction() {
    P2PublicSurfaceRetentionViewAuditAnchor anchor{};
    assert(anchor.retention_view_identity.view_id.value == 0);
    anchor.retention_view_identity.view_id = P2PublicSurfaceRetentionViewId{123};
    assert(anchor.retention_view_identity.view_id.value == 123);
    P2PublicSurfaceRetentionAuditAnchorSet anchor_set{};
    assert(anchor_set.retention_view_anchor.retention_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_retention_audit_anchor_default_construction" << std::endl;
}
