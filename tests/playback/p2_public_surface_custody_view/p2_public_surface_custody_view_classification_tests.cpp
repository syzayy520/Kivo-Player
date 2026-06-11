#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_custody_view/classification/p2_public_surface_custody_view_classification.h"

using namespace kivo::playback::p2_public_surface_custody_view;

void test_p2_public_surface_custody_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewKind::RetentionHeld) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewKind::SurfaceHeld) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewKind::ProofHeld) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewScope::RetentionBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewScope::CustodyBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCustodyViewScope::Unknown) == 3);
    P2PublicSurfaceCustodyViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceCustodyViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceCustodyViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_custody_view_classification_default_construction" << std::endl;
}
