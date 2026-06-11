#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_delta/delta/playback_p2_public_surface_delta.h"
#include "playback/p2_public_surface_delta/delta/p2_public_surface_delta_candidate.h"
#include "playback/p2_public_surface_delta/delta/p2_public_surface_delta_envelope.h"
#include "playback/p2_public_surface_delta/delta/p2_public_surface_delta_record.h"

using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_delta_delta_default_construction() {
    P2PublicSurfaceDeltaCandidate candidate{};
    assert(candidate.identity.delta_id.value == 0);
    assert(candidate.anchors.snapshot_anchor.snapshot_identity.snapshot_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceDeltaKind::Unknown);
    PlaybackP2PublicSurfaceDelta delta{};
    assert(delta.identity.delta_id.value == 0);
    P2PublicSurfaceDeltaEnvelope envelope{};
    assert(envelope.identity.delta_id.value == 0);
    P2PublicSurfaceDeltaRecord record{};
    assert(record.envelope.identity.delta_id.value == 0);
    assert(record.delta.identity.delta_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_delta_delta_default_construction" << std::endl;
}
