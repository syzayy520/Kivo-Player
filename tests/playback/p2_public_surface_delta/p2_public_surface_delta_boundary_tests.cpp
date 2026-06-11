#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_delta/identity/p2_public_surface_delta_identity.h"
#include "playback/p2_public_surface_delta/anchor/p2_public_surface_snapshot_delta_anchor.h"
#include "playback/p2_public_surface_delta/delta/playback_p2_public_surface_delta.h"
#include "playback/p2_public_surface_delta/outcome/p2_public_surface_delta_outcome.h"

using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_delta_boundary_cross_family() {
    P2PublicSurfaceSnapshotDeltaAnchor anchor{};
    anchor.snapshot_identity.snapshot_id = kivo::playback::p2_public_surface_snapshot::P2PublicSurfaceSnapshotId{123};
    assert(anchor.snapshot_identity.snapshot_id.value == 123);
    PlaybackP2PublicSurfaceDelta delta{
        .identity = P2PublicSurfaceDeltaIdentity{.delta_id = P2PublicSurfaceDeltaId{1}},
        .anchors = P2PublicSurfaceDeltaAnchorSet{.snapshot_anchor = anchor},
        .classification = P2PublicSurfaceDeltaClassification{.kind = P2PublicSurfaceDeltaKind::SurfaceDelta, .scope = P2PublicSurfaceDeltaScope::DeltaBoundary}
    };
    assert(delta.identity.delta_id.value == 1);
    assert(delta.anchors.snapshot_anchor.snapshot_identity.snapshot_id.value == 123);
    assert(delta.classification.kind == P2PublicSurfaceDeltaKind::SurfaceDelta);
    assert(delta.classification.scope == P2PublicSurfaceDeltaScope::DeltaBoundary);
    P2PublicSurfaceDeltaOutcome outcome{.identity = P2PublicSurfaceDeltaIdentity{.delta_id = P2PublicSurfaceDeltaId{42}}, .status = P2PublicSurfaceDeltaStatus::Recorded};
    assert(outcome.identity.delta_id.value == 42);
    assert(outcome.status == P2PublicSurfaceDeltaStatus::Recorded);
    std::cout << "PASS: test_p2_public_surface_delta_boundary_cross_family" << std::endl;
}
