#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/seek_public/classification/seek_public_classification.h"

using namespace kivo::playback::seek_public;

void test_seek_public_classification_default_construction() {
    assert(static_cast<std::uint8_t>(SeekPublicKind::Absolute) == 0);
    assert(static_cast<std::uint8_t>(SeekPublicKind::Relative) == 1);
    assert(static_cast<std::uint8_t>(SeekPublicKind::Resume) == 2);
    assert(static_cast<std::uint8_t>(SeekPublicKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(SeekPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(SeekPublicScope::StreamSelection) == 1);
    assert(static_cast<std::uint8_t>(SeekPublicScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(SeekPublicScope::Unknown) == 3);
    SeekPublicClassification cls{};
    assert(cls.kind == SeekPublicKind::Unknown);
    assert(cls.scope == SeekPublicScope::Unknown);
    std::cout << "PASS: test_seek_public_classification_default_construction" << std::endl;
}
