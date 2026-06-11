#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_snapshot/anchor/p2_public_surface_observation_snapshot_anchor.h"
#include "playback/p2_public_surface_snapshot/anchor/p2_public_surface_snapshot_anchor_set.h"

using namespace kivo::playback::p2_public_surface_snapshot;
using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_snapshot_anchor_default_construction() {
    P2PublicSurfaceObservationSnapshotAnchor anchor{};
    assert(anchor.observation_identity.observation_id.value == 0);
    anchor.observation_identity.observation_id = P2PublicSurfaceObservationId{123};
    assert(anchor.observation_identity.observation_id.value == 123);
    P2PublicSurfaceSnapshotAnchorSet anchor_set{};
    assert(anchor_set.observation_anchor.observation_identity.observation_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_snapshot_anchor_default_construction" << std::endl;
}
