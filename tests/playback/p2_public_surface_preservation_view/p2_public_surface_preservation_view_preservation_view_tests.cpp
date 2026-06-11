#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_preservation_view/preservation_view/playback_p2_public_surface_preservation_view.h"
#include "playback/p2_public_surface_preservation_view/preservation_view/p2_public_surface_preservation_view_candidate.h"
#include "playback/p2_public_surface_preservation_view/preservation_view/p2_public_surface_preservation_view_envelope.h"
#include "playback/p2_public_surface_preservation_view/preservation_view/p2_public_surface_preservation_view_record.h"

using namespace kivo::playback::p2_public_surface_preservation_view;

void test_p2_public_surface_preservation_view_preservation_view_default_construction() {
    P2PublicSurfacePreservationViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.custody_view_anchor.custody_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfacePreservationViewKind::Unknown);
    PlaybackP2PublicSurfacePreservationView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfacePreservationViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfacePreservationViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_preservation_view_preservation_view_default_construction" << std::endl;
}
