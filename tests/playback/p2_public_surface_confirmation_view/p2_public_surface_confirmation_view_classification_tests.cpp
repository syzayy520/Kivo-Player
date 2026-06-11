#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/classification/p2_public_surface_confirmation_view_classification.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewKind::CommitmentConfirmed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewKind::SurfaceConfirmed) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewKind::ProofConfirmed) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewScope::CommitmentBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewScope::ConfirmationBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceConfirmationViewScope::Unknown) == 3);
    P2PublicSurfaceConfirmationViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceConfirmationViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceConfirmationViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_confirmation_view_classification_default_construction" << std::endl;
}
