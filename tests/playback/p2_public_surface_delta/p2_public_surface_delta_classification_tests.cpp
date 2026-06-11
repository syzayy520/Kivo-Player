#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_delta/classification/p2_public_surface_delta_classification.h"

using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_delta_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaKind::SnapshotDelta) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaKind::SurfaceDelta) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaKind::ProofDelta) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaScope::SnapshotBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaScope::DeltaBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceDeltaScope::Unknown) == 3);
    P2PublicSurfaceDeltaClassification classification{};
    assert(classification.kind == P2PublicSurfaceDeltaKind::Unknown);
    assert(classification.scope == P2PublicSurfaceDeltaScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_delta_classification_default_construction" << std::endl;
}
