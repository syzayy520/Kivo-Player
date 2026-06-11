#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_readback/classification/p2_public_readback_classification.h"

using namespace kivo::playback::p2_public_readback;

void test_p2_public_readback_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicReadbackKind::SurfaceSnapshot) == 0);
    assert(static_cast<std::uint8_t>(P2PublicReadbackKind::AdmissionSnapshot) == 1);
    assert(static_cast<std::uint8_t>(P2PublicReadbackKind::ChainSnapshot) == 2);
    assert(static_cast<std::uint8_t>(P2PublicReadbackKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicReadbackScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicReadbackScope::AdmissionBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicReadbackScope::ReadbackBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicReadbackScope::Unknown) == 3);
    P2PublicReadbackClassification classification{};
    assert(classification.kind == P2PublicReadbackKind::Unknown);
    assert(classification.scope == P2PublicReadbackScope::Unknown);
    std::cout << "PASS: test_p2_public_readback_classification_default_construction" << std::endl;
}
