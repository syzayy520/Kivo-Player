#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_retention_view/classification/p2_public_surface_retention_view_classification.h"

using namespace kivo::playback::p2_public_surface_retention_view;

void test_p2_public_surface_retention_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewKind::PersistenceRetained) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewKind::SurfaceRetained) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewKind::ProofRetained) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewScope::PersistenceBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewScope::RetentionBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceRetentionViewScope::Unknown) == 3);
    P2PublicSurfaceRetentionViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceRetentionViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceRetentionViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_retention_view_classification_default_construction" << std::endl;
}
