#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_intake/classification/p2_public_intake_classification.h"

using namespace kivo::playback::p2_public_intake;

void test_p2_public_intake_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicIntakeKind::SurfaceOpen) == 0);
    assert(static_cast<std::uint8_t>(P2PublicIntakeKind::SurfaceClose) == 1);
    assert(static_cast<std::uint8_t>(P2PublicIntakeKind::PhaseAdvance) == 2);
    assert(static_cast<std::uint8_t>(P2PublicIntakeKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicIntakeScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicIntakeScope::ClosureBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicIntakeScope::IntakeBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicIntakeScope::Unknown) == 3);
    P2PublicIntakeClassification classification{};
    assert(classification.kind == P2PublicIntakeKind::Unknown);
    assert(classification.scope == P2PublicIntakeScope::Unknown);
    std::cout << "PASS: test_p2_public_intake_classification_default_construction" << std::endl;
}
