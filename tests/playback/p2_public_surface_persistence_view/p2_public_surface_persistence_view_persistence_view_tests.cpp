#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_persistence_view/persistence_view/playback_p2_public_surface_persistence_view.h"
#include "playback/p2_public_surface_persistence_view/persistence_view/p2_public_surface_persistence_view_candidate.h"
#include "playback/p2_public_surface_persistence_view/persistence_view/p2_public_surface_persistence_view_envelope.h"
#include "playback/p2_public_surface_persistence_view/persistence_view/p2_public_surface_persistence_view_record.h"

using namespace kivo::playback::p2_public_surface_persistence_view;

void test_p2_public_surface_persistence_view_persistence_view_default_construction() {
    P2PublicSurfacePersistenceViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.durability_anchor.durability_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfacePersistenceViewKind::Unknown);
    PlaybackP2PublicSurfacePersistenceView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfacePersistenceViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfacePersistenceViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_persistence_view_persistence_view_default_construction" << std::endl;
}
