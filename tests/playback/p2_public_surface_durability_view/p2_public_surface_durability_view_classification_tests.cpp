#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_durability_view/classification/p2_public_surface_durability_view_classification.h"

using namespace kivo::playback::p2_public_surface_durability_view;

void test_p2_public_surface_durability_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewKind::ContinuityDurable) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewKind::SurfaceDurable) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewKind::ProofDurable) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewScope::ContinuityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewScope::DurabilityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDurabilityViewScope::Unknown) == 3);
    P2PublicSurfaceDurabilityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceDurabilityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceDurabilityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_durability_view_classification_default_construction" << std::endl;
}
