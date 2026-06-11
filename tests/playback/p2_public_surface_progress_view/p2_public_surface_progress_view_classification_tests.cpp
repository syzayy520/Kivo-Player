#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_progress_view/classification/p2_public_surface_progress_view_classification.h"

using namespace kivo::playback::p2_public_surface_progress_view;

void test_p2_public_surface_progress_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewKind::StateProgress) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewKind::SurfaceProgress) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewKind::ProofProgress) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewScope::StateViewBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewScope::ProgressViewBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceProgressViewScope::Unknown) == 3);
    P2PublicSurfaceProgressViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceProgressViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceProgressViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_progress_view_classification_default_construction" << std::endl;
}
