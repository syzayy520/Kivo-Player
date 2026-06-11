#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_availability_view/classification/p2_public_surface_availability_view_classification.h"

using namespace kivo::playback::p2_public_surface_availability_view;

void test_p2_public_surface_availability_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewKind::ConsistencyAvailable) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewKind::SurfaceAvailable) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewKind::ProofAvailable) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewScope::ConsistencyBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewScope::AvailabilityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceAvailabilityViewScope::Unknown) == 3);
    P2PublicSurfaceAvailabilityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceAvailabilityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceAvailabilityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_availability_view_classification_default_construction" << std::endl;
}
