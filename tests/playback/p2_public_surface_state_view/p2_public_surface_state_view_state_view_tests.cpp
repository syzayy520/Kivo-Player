#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_state_view/state_view/playback_p2_public_surface_state_view.h"
#include "playback/p2_public_surface_state_view/state_view/p2_public_surface_state_view_candidate.h"
#include "playback/p2_public_surface_state_view/state_view/p2_public_surface_state_view_envelope.h"
#include "playback/p2_public_surface_state_view/state_view/p2_public_surface_state_view_record.h"

using namespace kivo::playback::p2_public_surface_state_view;

void test_p2_public_surface_state_view_state_view_default_construction() {
    P2PublicSurfaceStateViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.closure_anchor.closure_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceStateViewKind::Unknown);
    PlaybackP2PublicSurfaceStateView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceStateViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceStateViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_state_view_state_view_default_construction" << std::endl;
}
