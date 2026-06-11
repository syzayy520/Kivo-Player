#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_eligibility_view/eligibility_view/playback_p2_public_surface_eligibility_view.h"
#include "playback/p2_public_surface_eligibility_view/eligibility_view/p2_public_surface_eligibility_view_candidate.h"
#include "playback/p2_public_surface_eligibility_view/eligibility_view/p2_public_surface_eligibility_view_envelope.h"
#include "playback/p2_public_surface_eligibility_view/eligibility_view/p2_public_surface_eligibility_view_record.h"

using namespace kivo::playback::p2_public_surface_eligibility_view;

void test_p2_public_surface_eligibility_view_eligibility_view_default_construction() {
    P2PublicSurfaceEligibilityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.readiness_anchor.readiness_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceEligibilityViewKind::Unknown);
    PlaybackP2PublicSurfaceEligibilityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceEligibilityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceEligibilityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_eligibility_view_eligibility_view_default_construction" << std::endl;
}
