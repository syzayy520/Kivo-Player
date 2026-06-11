#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_preservation_view/classification/p2_public_surface_preservation_view_classification.h"

using namespace kivo::playback::p2_public_surface_preservation_view;

void test_p2_public_surface_preservation_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewKind::CustodyPreserved) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewKind::SurfacePreserved) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewKind::ProofPreserved) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewScope::CustodyBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewScope::PreservationBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePreservationViewScope::Unknown) == 3);
    P2PublicSurfacePreservationViewClassification classification{};
    assert(classification.kind == P2PublicSurfacePreservationViewKind::Unknown);
    assert(classification.scope == P2PublicSurfacePreservationViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_preservation_view_classification_default_construction" << std::endl;
}
