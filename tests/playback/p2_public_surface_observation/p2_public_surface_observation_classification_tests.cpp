#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_observation/classification/p2_public_surface_observation_classification.h"

using namespace kivo::playback::p2_public_surface_observation;

void test_p2_public_surface_observation_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationKind::ChainObservation) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationKind::SurfaceObservation) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationKind::ProofObservation) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationScope::ChainBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationScope::ObservationBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceObservationScope::Unknown) == 3);
    P2PublicSurfaceObservationClassification classification{};
    assert(classification.kind == P2PublicSurfaceObservationKind::Unknown);
    assert(classification.scope == P2PublicSurfaceObservationScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_observation_classification_default_construction" << std::endl;
}
