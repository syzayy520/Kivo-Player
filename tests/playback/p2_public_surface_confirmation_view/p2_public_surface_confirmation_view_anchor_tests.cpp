#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/anchor/p2_public_surface_commitment_confirmation_view_anchor.h"
#include "playback/p2_public_surface_confirmation_view/anchor/p2_public_surface_confirmation_view_anchor_set.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;
using namespace kivo::playback::p2_public_surface_commitment_view;

void test_p2_public_surface_confirmation_view_anchor_default_construction() {
    P2PublicSurfaceCommitmentConfirmationViewAnchor anchor{};
    assert(anchor.commitment_view_identity.view_id.value == 0);
    anchor.commitment_view_identity.view_id = P2PublicSurfaceCommitmentViewId{123};
    assert(anchor.commitment_view_identity.view_id.value == 123);
    P2PublicSurfaceConfirmationViewAnchorSet anchor_set{};
    assert(anchor_set.commitment_view_anchor.commitment_view_identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_confirmation_view_anchor_default_construction" << std::endl;
}
