#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_progress_view/progress_view/playback_p2_public_surface_progress_view.h"
#include "playback/p2_public_surface_progress_view/progress_view/p2_public_surface_progress_view_candidate.h"
#include "playback/p2_public_surface_progress_view/progress_view/p2_public_surface_progress_view_envelope.h"
#include "playback/p2_public_surface_progress_view/progress_view/p2_public_surface_progress_view_record.h"

using namespace kivo::playback::p2_public_surface_progress_view;

void test_p2_public_surface_progress_view_progress_view_default_construction() {
    P2PublicSurfaceProgressViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.state_view_anchor.state_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceProgressViewKind::Unknown);
    PlaybackP2PublicSurfaceProgressView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceProgressViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceProgressViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_progress_view_progress_view_default_construction" << std::endl;
}
