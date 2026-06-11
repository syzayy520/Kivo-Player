#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/confirmation_view/playback_p2_public_surface_confirmation_view.h"
#include "playback/p2_public_surface_confirmation_view/confirmation_view/p2_public_surface_confirmation_view_candidate.h"
#include "playback/p2_public_surface_confirmation_view/confirmation_view/p2_public_surface_confirmation_view_envelope.h"
#include "playback/p2_public_surface_confirmation_view/confirmation_view/p2_public_surface_confirmation_view_record.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_view_confirmation_view_default_construction() {
    P2PublicSurfaceConfirmationViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.commitment_view_anchor.commitment_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceConfirmationViewKind::Unknown);
    PlaybackP2PublicSurfaceConfirmationView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceConfirmationViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceConfirmationViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_confirmation_view_confirmation_view_default_construction" << std::endl;
}
