#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/buffering_public/classification/buffering_public_classification.h"

using namespace kivo::playback::buffering_public;

void test_buffering_public_classification_default_construction() {
    assert(static_cast<std::uint8_t>(BufferingPublicKind::Priming) == 0);
    assert(static_cast<std::uint8_t>(BufferingPublicKind::Filling) == 1);
    assert(static_cast<std::uint8_t>(BufferingPublicKind::Stable) == 2);
    assert(static_cast<std::uint8_t>(BufferingPublicKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(BufferingPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(BufferingPublicScope::Seek) == 1);
    assert(static_cast<std::uint8_t>(BufferingPublicScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(BufferingPublicScope::Unknown) == 3);
    BufferingPublicClassification cls{};
    assert(cls.kind == BufferingPublicKind::Unknown);
    assert(cls.scope == BufferingPublicScope::Unknown);
    std::cout << "PASS: test_buffering_public_classification_default_construction" << std::endl;
}
