#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_availability_view/availability_view/playback_p2_public_surface_availability_view.h"
#include "playback/p2_public_surface_availability_view/availability_view/p2_public_surface_availability_view_candidate.h"
#include "playback/p2_public_surface_availability_view/availability_view/p2_public_surface_availability_view_envelope.h"
#include "playback/p2_public_surface_availability_view/availability_view/p2_public_surface_availability_view_record.h"

using namespace kivo::playback::p2_public_surface_availability_view;

void test_p2_public_surface_availability_view_availability_view_default_construction() {
    P2PublicSurfaceAvailabilityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.consistency_anchor.consistency_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceAvailabilityViewKind::Unknown);
    PlaybackP2PublicSurfaceAvailabilityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceAvailabilityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceAvailabilityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_availability_view_availability_view_default_construction" << std::endl;
}
