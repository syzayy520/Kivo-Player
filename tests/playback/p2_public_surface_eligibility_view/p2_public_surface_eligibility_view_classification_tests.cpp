#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_eligibility_view/classification/p2_public_surface_eligibility_view_classification.h"

using namespace kivo::playback::p2_public_surface_eligibility_view;

void test_p2_public_surface_eligibility_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewKind::ReadinessEligible) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewKind::SurfaceEligible) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewKind::ProofEligible) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewScope::ReadinessBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewScope::EligibilityBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceEligibilityViewScope::Unknown) == 3);
    P2PublicSurfaceEligibilityViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceEligibilityViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceEligibilityViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_eligibility_view_classification_default_construction" << std::endl;
}
