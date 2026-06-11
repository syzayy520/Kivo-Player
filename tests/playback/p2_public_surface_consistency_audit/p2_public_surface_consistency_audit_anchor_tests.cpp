#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_consistency_audit/anchor/p2_public_surface_progress_consistency_audit_anchor.h"
#include "playback/p2_public_surface_consistency_audit/anchor/p2_public_surface_consistency_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_consistency_audit;
using namespace kivo::playback::p2_public_surface_progress_view;

void test_p2_public_surface_consistency_audit_anchor_default_construction() {
    P2PublicSurfaceProgressConsistencyAuditAnchor anchor{};
    assert(anchor.progress_view_identity.view_id.value == 0);
    anchor.progress_view_identity.view_id = P2PublicSurfaceProgressViewId{123};
    assert(anchor.progress_view_identity.view_id.value == 123);
    P2PublicSurfaceConsistencyAuditAnchorSet anchor_set{};
    assert(anchor_set.progress_view_anchor.progress_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_consistency_audit_anchor_default_construction" << std::endl;
}
