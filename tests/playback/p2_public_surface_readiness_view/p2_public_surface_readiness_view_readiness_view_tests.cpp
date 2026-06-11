#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_view/readiness_view/playback_p2_public_surface_readiness_view.h"
#include "playback/p2_public_surface_readiness_view/readiness_view/p2_public_surface_readiness_view_candidate.h"
#include "playback/p2_public_surface_readiness_view/readiness_view/p2_public_surface_readiness_view_envelope.h"
#include "playback/p2_public_surface_readiness_view/readiness_view/p2_public_surface_readiness_view_record.h"

using namespace kivo::playback::p2_public_surface_readiness_view;

void test_p2_public_surface_readiness_view_readiness_view_default_construction() {
    P2PublicSurfaceReadinessViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.availability_view_anchor.availability_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceReadinessViewKind::Unknown);
    PlaybackP2PublicSurfaceReadinessView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceReadinessViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceReadinessViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_readiness_view_readiness_view_default_construction" << std::endl;
}
