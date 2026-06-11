#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/end_of_stream_public/classification/end_of_stream_public_classification.h"

using namespace kivo::playback::end_of_stream_public;

void test_end_of_stream_public_classification_default_construction() {
    assert(static_cast<std::uint8_t>(EndOfStreamPublicKind::Natural) == 0);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicKind::Forced) == 1);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicKind::Interrupted) == 2);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicScope::TrackTransition) == 1);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(EndOfStreamPublicScope::Unknown) == 3);
    EndOfStreamPublicClassification cls{};
    assert(cls.kind == EndOfStreamPublicKind::Unknown);
    assert(cls.scope == EndOfStreamPublicScope::Unknown);
    std::cout << "PASS: test_end_of_stream_public_classification_default_construction" << std::endl;
}
