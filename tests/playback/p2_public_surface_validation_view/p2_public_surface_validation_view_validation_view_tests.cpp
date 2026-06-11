#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_validation_view/validation_view/playback_p2_public_surface_validation_view.h"
#include "playback/p2_public_surface_validation_view/validation_view/p2_public_surface_validation_view_candidate.h"
#include "playback/p2_public_surface_validation_view/validation_view/p2_public_surface_validation_view_envelope.h"
#include "playback/p2_public_surface_validation_view/validation_view/p2_public_surface_validation_view_record.h"

using namespace kivo::playback::p2_public_surface_validation_view;

void test_p2_public_surface_validation_view_validation_view_default_construction() {
    P2PublicSurfaceValidationViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.confirmation_anchor.confirmation_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceValidationViewKind::Unknown);
    PlaybackP2PublicSurfaceValidationView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceValidationViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceValidationViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_validation_view_validation_view_default_construction" << std::endl;
}
