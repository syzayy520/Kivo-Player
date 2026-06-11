#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_surface_validation_view/classification/p2_public_surface_validation_view_classification.h"

using namespace kivo::playback::p2_public_surface_validation_view;

void test_p2_public_surface_validation_view_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewKind::ConfirmationValidated) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewKind::SurfaceValidated) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewKind::ProofValidated) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewScope::ConfirmationBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewScope::ValidationBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicSurfaceValidationViewScope::Unknown) == 3);
    P2PublicSurfaceValidationViewClassification classification{};
    assert(classification.kind == P2PublicSurfaceValidationViewKind::Unknown);
    assert(classification.scope == P2PublicSurfaceValidationViewScope::Unknown);
    std::cout << "PASS: test_p2_public_surface_validation_view_classification_default_construction" << std::endl;
}
