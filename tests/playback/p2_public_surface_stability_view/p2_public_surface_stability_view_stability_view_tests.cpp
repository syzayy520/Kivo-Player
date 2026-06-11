#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_view/stability_view/playback_p2_public_surface_stability_view.h"
#include "playback/p2_public_surface_stability_view/stability_view/p2_public_surface_stability_view_candidate.h"
#include "playback/p2_public_surface_stability_view/stability_view/p2_public_surface_stability_view_envelope.h"
#include "playback/p2_public_surface_stability_view/stability_view/p2_public_surface_stability_view_record.h"

using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_view_stability_view_default_construction() {
    P2PublicSurfaceStabilityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.coherence_view_anchor.coherence_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceStabilityViewKind::Unknown);
    PlaybackP2PublicSurfaceStabilityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceStabilityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceStabilityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_stability_view_stability_view_default_construction" << std::endl;
}
