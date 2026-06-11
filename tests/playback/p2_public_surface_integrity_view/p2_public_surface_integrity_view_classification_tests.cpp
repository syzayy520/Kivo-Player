#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_integrity_view/classification/p2_public_surface_integrity_view_classification.h"

using namespace kivo::playback::p2_public_surface_integrity_view;

void test_p2_public_surface_integrity_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewKind::ValidationIntact) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewKind::SurfaceIntact) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewKind::ProofIntact) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewScope::ValidationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewScope::IntegrityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceIntegrityViewScope::Unknown) == 3);
    P2PublicSurfaceIntegrityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceIntegrityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceIntegrityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_integrity_view_classification_default_construction" << std::endl;
}
