#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_final_audit/anchor/p2_public_surface_source_final_anchor.h"
#include "playback/p2_public_surface_final_audit/anchor/p2_public_surface_final_audit_anchor_set.h"

using namespace kivo::playback::p2_public_surface_final_audit;

void test_p2_public_surface_final_audit_anchor_default_construction() {
    P2PublicSurfaceSourceFinalAnchor anchor{};
    assert(anchor.source_identity_token == 0);
    anchor.source_identity_token = 123;
    assert(anchor.source_identity_token == 123);
    P2PublicSurfaceFinalAuditAnchorSet anchor_set{};
    assert(anchor_set.source_anchor.source_identity_token == 0);
    std::cout << "PASS: test_p2_public_surface_final_audit_anchor_default_construction" << std::endl;
}
