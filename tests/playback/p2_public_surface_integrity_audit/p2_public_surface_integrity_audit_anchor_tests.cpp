#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_audit/anchor/p2_public_surface_integrity_view_audit_anchor.h"
#include "playback/p2_public_surface_integrity_audit/anchor/p2_public_surface_integrity_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_integrity_audit;
using namespace kivo::playback::p2_public_surface_integrity_view;

void test_p2_public_surface_integrity_audit_anchor_default_construction() {
    P2PublicSurfaceIntegrityViewAuditAnchor anchor{};
    assert(anchor.integrity_view_identity.view_id.value == 0);
    anchor.integrity_view_identity.view_id = P2PublicSurfaceIntegrityViewId{123};
    assert(anchor.integrity_view_identity.view_id.value == 123);
    P2PublicSurfaceIntegrityAuditAnchorSet anchor_set{};
    assert(anchor_set.integrity_view_anchor.integrity_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_integrity_audit_anchor_default_construction" << std::endl;
}
