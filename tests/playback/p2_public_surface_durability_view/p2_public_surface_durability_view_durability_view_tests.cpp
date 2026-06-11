#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_view/durability_view/playback_p2_public_surface_durability_view.h"
#include "playback/p2_public_surface_durability_view/durability_view/p2_public_surface_durability_view_candidate.h"
#include "playback/p2_public_surface_durability_view/durability_view/p2_public_surface_durability_view_envelope.h"
#include "playback/p2_public_surface_durability_view/durability_view/p2_public_surface_durability_view_record.h"

using namespace kivo::playback::p2_public_surface_durability_view;

void test_p2_public_surface_durability_view_durability_view_default_construction() {
    P2PublicSurfaceDurabilityViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.continuity_view_anchor.continuity_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceDurabilityViewKind::Unknown);
    PlaybackP2PublicSurfaceDurabilityView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceDurabilityViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceDurabilityViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_durability_view_durability_view_default_construction" << std::endl;
}
