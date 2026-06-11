#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_snapshot/identity/p2_public_surface_snapshot_identity.h"
#include "playback/p2_public_surface_snapshot/anchor/p2_public_surface_observation_snapshot_anchor.h"
#include "playback/p2_public_surface_snapshot/snapshot/playback_p2_public_surface_snapshot.h"
#include "playback/p2_public_surface_snapshot/outcome/p2_public_surface_snapshot_outcome.h"

using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_snapshot_boundary_cross_family() {
    P2PublicSurfaceObservationSnapshotAnchor anchor{};
    anchor.observation_identity.observation_id = kivo::playback::p2_public_surface_observation::P2PublicSurfaceObservationId{123};
    assert(anchor.observation_identity.observation_id.value == 123);
    PlaybackP2PublicSurfaceSnapshot snapshot{
        .identity = P2PublicSurfaceSnapshotIdentity{.snapshot_id = P2PublicSurfaceSnapshotId{1}},
        .anchors = P2PublicSurfaceSnapshotAnchorSet{.observation_anchor = anchor},
        .classification = P2PublicSurfaceSnapshotClassification{.kind = P2PublicSurfaceSnapshotKind::SurfaceSnapshot, .scope = P2PublicSurfaceSnapshotScope::SnapshotBoundary}
    };
    assert(snapshot.identity.snapshot_id.value == 1);
    assert(snapshot.anchors.observation_anchor.observation_identity.observation_id.value == 123);
    assert(snapshot.classification.kind == P2PublicSurfaceSnapshotKind::SurfaceSnapshot);
    assert(snapshot.classification.scope == P2PublicSurfaceSnapshotScope::SnapshotBoundary);
    P2PublicSurfaceSnapshotOutcome outcome{.identity = P2PublicSurfaceSnapshotIdentity{.snapshot_id = P2PublicSurfaceSnapshotId{42}}, .status = P2PublicSurfaceSnapshotStatus::Recorded};
    assert(outcome.identity.snapshot_id.value == 42);
    assert(outcome.status == P2PublicSurfaceSnapshotStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_snapshot_boundary_cross_family" << std::endl;
}
