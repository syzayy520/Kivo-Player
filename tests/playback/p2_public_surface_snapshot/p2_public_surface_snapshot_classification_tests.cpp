#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_snapshot/classification/p2_public_surface_snapshot_classification.h"

using namespace kivo::playback::p2_public_surface_snapshot;

void test_p2_public_surface_snapshot_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotKind::ObservationSnapshot) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotKind::SurfaceSnapshot) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotKind::ProofSnapshot) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotScope::ObservationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotScope::SnapshotBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceSnapshotScope::Unknown) == 3);
    P2PublicSurfaceSnapshotClassification classification{};
    assert(classification.kind == P2PublicSurfaceSnapshotKind::Unknown);
    assert(classification.scope == P2PublicSurfaceSnapshotScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_snapshot_classification_default_construction" << std::endl;
}
