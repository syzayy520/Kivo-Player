#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_snapshot/snapshot/playback_p2_public_surface_snapshot.h"
#include "playback/p2_public_surface_snapshot/snapshot/p2_public_surface_snapshot_candidate.h"
#include "playback/p2_public_surface_snapshot/snapshot/p2_public_surface_snapshot_envelope.h"
#include "playback/p2_public_surface_snapshot/snapshot/p2_public_surface_snapshot_record.h"

using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_snapshot_snapshot_default_construction() {
    P2PublicSurfaceSnapshotCandidate candidate{};
    assert(candidate.identity.snapshot_id.value == 0);
    assert(candidate.anchors.observation_anchor.observation_identity.observation_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceSnapshotKind::Unknown);
    PlaybackP2PublicSurfaceSnapshot snapshot{};
    assert(snapshot.identity.snapshot_id.value == 0);
    P2PublicSurfaceSnapshotEnvelope envelope{};
    assert(envelope.identity.snapshot_id.value == 0);
    P2PublicSurfaceSnapshotRecord record{};
    assert(record.envelope.identity.snapshot_id.value == 0);
    assert(record.snapshot.identity.snapshot_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_snapshot_snapshot_default_construction" << std::endl;
}
