#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_custody_view/custody_view/playback_p2_public_surface_custody_view.h"
#include "playback/p2_public_surface_custody_view/custody_view/p2_public_surface_custody_view_candidate.h"
#include "playback/p2_public_surface_custody_view/custody_view/p2_public_surface_custody_view_envelope.h"
#include "playback/p2_public_surface_custody_view/custody_view/p2_public_surface_custody_view_record.h"

using namespace kivo::playback::p2_public_surface_custody_view;

void test_p2_public_surface_custody_view_custody_view_default_construction() {
    P2PublicSurfaceCustodyViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.retention_anchor.retention_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceCustodyViewKind::Unknown);
    PlaybackP2PublicSurfaceCustodyView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceCustodyViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceCustodyViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_custody_view_custody_view_default_construction" << std::endl;
}
