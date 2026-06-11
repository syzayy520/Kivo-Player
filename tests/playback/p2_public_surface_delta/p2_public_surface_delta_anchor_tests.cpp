#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_delta/anchor/p2_public_surface_snapshot_delta_anchor.h"
#include "playback/p2_public_surface_delta/anchor/p2_public_surface_delta_anchor_set.h"

using namespace kivo::playback::p2_public_surface_delta;
using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_delta_anchor_default_construction() {
    P2PublicSurfaceSnapshotDeltaAnchor anchor{};
    assert(anchor.snapshot_identity.snapshot_id.value == 0);
    anchor.snapshot_identity.snapshot_id = P2PublicSurfaceSnapshotId{123};
    assert(anchor.snapshot_identity.snapshot_id.value == 123);
    P2PublicSurfaceDeltaAnchorSet anchor_set{};
    assert(anchor_set.snapshot_anchor.snapshot_identity.snapshot_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_delta_anchor_default_construction" << std::endl;
}
