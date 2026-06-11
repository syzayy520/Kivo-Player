#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_stability_view/classification/p2_public_surface_stability_view_classification.h"

using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewKind::CoherenceStable) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewKind::SurfaceStable) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewKind::ProofStable) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewScope::CoherenceBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewScope::StabilityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStabilityViewScope::Unknown) == 3);
    P2PublicSurfaceStabilityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceStabilityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceStabilityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_stability_view_classification_default_construction" << std::endl;
}
