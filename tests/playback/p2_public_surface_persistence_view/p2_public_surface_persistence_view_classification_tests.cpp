#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_persistence_view/classification/p2_public_surface_persistence_view_classification.h"

using namespace kivo::playback::p2_public_surface_persistence_view;

void test_p2_public_surface_persistence_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewKind::DurabilityPersistent) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewKind::SurfacePersistent) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewKind::ProofPersistent) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewScope::DurabilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewScope::PersistenceBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfacePersistenceViewScope::Unknown) == 3);
    P2PublicSurfacePersistenceViewClassification classification{};
    assert(classification.kind == P2PublicSurfacePersistenceViewKind::Unknown);
    assert(classification.scope == P2PublicSurfacePersistenceViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_persistence_view_classification_default_construction" << std::endl;
}
