#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_state_view/classification/p2_public_surface_state_view_classification.h"

using namespace kivo::playback::p2_public_surface_state_view;

void test_p2_public_surface_state_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewKind::ClosureState) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewKind::SurfaceState) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewKind::ProofState) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewScope::ClosureBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewScope::StateViewBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceStateViewScope::Unknown) == 3);
    P2PublicSurfaceStateViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceStateViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceStateViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_state_view_classification_default_construction" << std::endl;
}
