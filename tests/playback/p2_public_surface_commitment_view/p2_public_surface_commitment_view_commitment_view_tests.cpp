#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_commitment_view/commitment_view/playback_p2_public_surface_commitment_view.h"
#include "playback/p2_public_surface_commitment_view/commitment_view/p2_public_surface_commitment_view_candidate.h"
#include "playback/p2_public_surface_commitment_view/commitment_view/p2_public_surface_commitment_view_envelope.h"
#include "playback/p2_public_surface_commitment_view/commitment_view/p2_public_surface_commitment_view_record.h"

using namespace kivo::playback::p2_public_surface_commitment_view;

void test_p2_public_surface_commitment_view_commitment_view_default_construction() {
    P2PublicSurfaceCommitmentViewCandidate candidate{};
    assert(candidate.identity.view_id.value == 0);
    assert(candidate.anchors.activation_anchor.activation_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceCommitmentViewKind::Unknown);
    PlaybackP2PublicSurfaceCommitmentView view{};
    assert(view.identity.view_id.value == 0);
    P2PublicSurfaceCommitmentViewEnvelope envelope{};
    assert(envelope.identity.view_id.value == 0);
    P2PublicSurfaceCommitmentViewRecord record{};
    assert(record.envelope.identity.view_id.value == 0);
    assert(record.view.identity.view_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_commitment_view_commitment_view_default_construction" << std::endl;
}
