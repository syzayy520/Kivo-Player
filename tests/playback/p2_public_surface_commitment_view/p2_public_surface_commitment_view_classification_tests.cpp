#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_commitment_view/classification/p2_public_surface_commitment_view_classification.h"

using namespace kivo::playback::p2_public_surface_commitment_view;

void test_p2_public_surface_commitment_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewKind::ActivationCommitted) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewKind::SurfaceCommitted) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewKind::ProofCommitted) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewScope::ActivationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewScope::CommitmentBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCommitmentViewScope::Unknown) == 3);
    P2PublicSurfaceCommitmentViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceCommitmentViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceCommitmentViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_commitment_view_classification_default_construction" << std::endl;
}
