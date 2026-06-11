#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_activation_view/classification/p2_public_surface_activation_view_classification.h"

using namespace kivo::playback::p2_public_surface_activation_view;

void test_p2_public_surface_activation_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewKind::EligibilityActive) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewKind::SurfaceActive) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewKind::ProofActive) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewScope::EligibilityBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewScope::ActivationBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceActivationViewScope::Unknown) == 3);
    P2PublicSurfaceActivationViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceActivationViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceActivationViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_activation_view_classification_default_construction" << std::endl;
}
