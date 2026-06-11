#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_coherence_view/classification/p2_public_surface_coherence_view_classification.h"

using namespace kivo::playback::p2_public_surface_coherence_view;

void test_p2_public_surface_coherence_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewKind::IntegrityCoherent) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewKind::SurfaceCoherent) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewKind::ProofCoherent) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewScope::IntegrityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewScope::CoherenceBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceCoherenceViewScope::Unknown) == 3);
    P2PublicSurfaceCoherenceViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceCoherenceViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceCoherenceViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_coherence_view_classification_default_construction" << std::endl;
}
