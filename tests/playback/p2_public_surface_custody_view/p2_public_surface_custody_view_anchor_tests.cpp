#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_custody_view/anchor/p2_public_surface_retention_custody_view_anchor.h"
#include "playback/p2_public_surface_custody_view/anchor/p2_public_surface_custody_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_custody_view;
using namespace kivo::playback::p2_public_surface_retention_audit;

void test_p2_public_surface_custody_view_anchor_default_construction() {
    P2PublicSurfaceRetentionCustodyViewAnchor anchor{};
    assert(anchor.retention_identity.audit_id.value == 0);
    anchor.retention_identity.audit_id = P2PublicSurfaceRetentionAuditId{123};
    assert(anchor.retention_identity.audit_id.value == 123);
    P2PublicSurfaceCustodyViewAnchorSet anchor_set{};
    assert(anchor_set.retention_anchor.retention_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_custody_view_anchor_default_construction" << std::endl;
}
