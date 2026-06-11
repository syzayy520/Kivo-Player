#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_continuity_view/classification/p2_public_surface_continuity_view_classification.h"

using namespace kivo::playback::p2_public_surface_continuity_view;

void test_p2_public_surface_continuity_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewKind::StabilityContinuous) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewKind::SurfaceContinuous) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewKind::ProofContinuous) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewScope::StabilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewScope::ContinuityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceContinuityViewScope::Unknown) == 3);
    P2PublicSurfaceContinuityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceContinuityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceContinuityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_continuity_view_classification_default_construction" << std::endl;
}
