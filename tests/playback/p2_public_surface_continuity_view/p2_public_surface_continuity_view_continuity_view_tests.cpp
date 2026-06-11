#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_continuity_view/continuity_view/playback_p2_public_surface_continuity_view.h"
#include "playback/p2_public_surface_continuity_view/continuity_view/p2_public_surface_continuity_view_candidate.h"
#include "playback/p2_public_surface_continuity_view/continuity_view/p2_public_surface_continuity_view_envelope.h"
#include "playback/p2_public_surface_continuity_view/continuity_view/p2_public_surface_continuity_view_record.h"

using namespace kivo::playback::p2_public_surface_continuity_view;

void test_p2_public_surface_continuity_view_continuity_view_default_construction() {
    P2PublicSurfaceContinuityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.stability_anchor.stability_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceContinuityViewKind::Unknown);
    PlaybackP2PublicSurfaceContinuityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceContinuityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceContinuityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_continuity_view_continuity_view_default_construction" << std::endl;
}
