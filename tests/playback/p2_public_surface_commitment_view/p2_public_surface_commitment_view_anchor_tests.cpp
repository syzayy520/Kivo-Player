#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_commitment_view/anchor/p2_public_surface_activation_commitment_view_anchor.h"
#include "playback/p2_public_surface_commitment_view/anchor/p2_public_surface_commitment_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_commitment_view;
using namespace kivo::playback::p2_public_surface_activation_audit;

void test_p2_public_surface_commitment_view_anchor_default_construction() {
    P2PublicSurfaceActivationCommitmentViewAnchor anchor{};
    assert(anchor.activation_identity.audit_id.value == 0);
    anchor.activation_identity.audit_id = P2PublicSurfaceActivationAuditId{123};
    assert(anchor.activation_identity.audit_id.value == 123);
    P2PublicSurfaceCommitmentViewAnchorSet anchor_set{};
    assert(anchor_set.activation_anchor.activation_identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_commitment_view_anchor_default_construction" << std::endl;
}
