#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/coherence_view/playback_p2_public_surface_coherence_view.h"
#include "playback/p2_public_surface_coherence_view/coherence_view/p2_public_surface_coherence_view_candidate.h"
#include "playback/p2_public_surface_coherence_view/coherence_view/p2_public_surface_coherence_view_envelope.h"
#include "playback/p2_public_surface_coherence_view/coherence_view/p2_public_surface_coherence_view_record.h"

using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_coherence_view_coherence_view_default_construction() {
    P2PublicSurfaceCoherenceViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.integrity_anchor.integrity_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceCoherenceViewKind::Unknown);
    PlaybackP2PublicSurfaceCoherenceView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceCoherenceViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceCoherenceViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_coherence_view_coherence_view_default_construction" << std::endl;
}
