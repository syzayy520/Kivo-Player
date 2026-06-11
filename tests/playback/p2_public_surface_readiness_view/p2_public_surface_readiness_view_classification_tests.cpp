#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_readiness_view/classification/p2_public_surface_readiness_view_classification.h"

using namespace kivo::playback::p2_public_surface_readiness_view;

void test_p2_public_surface_readiness_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewKind::AvailabilityReady) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewKind::SurfaceReady) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewKind::ProofReady) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewScope::AvailabilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewScope::ReadinessBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceReadinessViewScope::Unknown) == 3);
    P2PublicSurfaceReadinessViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceReadinessViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceReadinessViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_readiness_view_classification_default_construction" << std::endl;
}
