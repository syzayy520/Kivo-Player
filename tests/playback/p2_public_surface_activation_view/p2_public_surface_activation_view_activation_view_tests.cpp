#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_view/activation_view/playback_p2_public_surface_activation_view.h"
#include "playback/p2_public_surface_activation_view/activation_view/p2_public_surface_activation_view_candidate.h"
#include "playback/p2_public_surface_activation_view/activation_view/p2_public_surface_activation_view_envelope.h"
#include "playback/p2_public_surface_activation_view/activation_view/p2_public_surface_activation_view_record.h"

using namespace kivo::playback::p2_public_surface_activation_view;

void test_p2_public_surface_activation_view_activation_view_default_construction() {
    P2PublicSurfaceActivationViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.eligibility_view_anchor.eligibility_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceActivationViewKind::Unknown);
    PlaybackP2PublicSurfaceActivationView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceActivationViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceActivationViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_activation_view_activation_view_default_construction" << std::endl;
}
