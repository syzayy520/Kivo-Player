#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_view/retention_view/playback_p2_public_surface_retention_view.h"
#include "playback/p2_public_surface_retention_view/retention_view/p2_public_surface_retention_view_candidate.h"
#include "playback/p2_public_surface_retention_view/retention_view/p2_public_surface_retention_view_envelope.h"
#include "playback/p2_public_surface_retention_view/retention_view/p2_public_surface_retention_view_record.h"

using namespace kivo::playback::p2_public_surface_retention_view;

void test_p2_public_surface_retention_view_retention_view_default_construction() {
    P2PublicSurfaceRetentionViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.persistence_view_anchor.persistence_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceRetentionViewKind::Unknown);
    PlaybackP2PublicSurfaceRetentionView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceRetentionViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceRetentionViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_retention_view_retention_view_default_construction" << std::endl;
}
