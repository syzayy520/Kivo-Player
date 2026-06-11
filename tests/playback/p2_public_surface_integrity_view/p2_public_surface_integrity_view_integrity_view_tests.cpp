#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_view/integrity_view/playback_p2_public_surface_integrity_view.h"
#include "playback/p2_public_surface_integrity_view/integrity_view/p2_public_surface_integrity_view_candidate.h"
#include "playback/p2_public_surface_integrity_view/integrity_view/p2_public_surface_integrity_view_envelope.h"
#include "playback/p2_public_surface_integrity_view/integrity_view/p2_public_surface_integrity_view_record.h"

using namespace kivo::playback::p2_public_surface_integrity_view;

void test_p2_public_surface_integrity_view_integrity_view_default_construction() {
    P2PublicSurfaceIntegrityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.validation_view_anchor.validation_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceIntegrityViewKind::Unknown);
    PlaybackP2PublicSurfaceIntegrityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceIntegrityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceIntegrityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_integrity_view_integrity_view_default_construction" << std::endl;
}
