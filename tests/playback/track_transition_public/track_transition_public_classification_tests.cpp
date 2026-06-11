#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/track_transition_public/classification/track_transition_public_classification.h"

using namespace kivo::playback::track_transition_public;

void test_track_transition_public_classification_default_construction() {
    assert(static_cast<std::uint8_t>(TrackTransitionPublicKind::Next) == 0);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicKind::Previous) == 1);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicKind::Direct) == 2);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicScope::Buffering) == 1);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicScope::Timeline) == 2);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicScope::Unknown) == 3);
    TrackTransitionPublicClassification cls{};
    assert(cls.kind == TrackTransitionPublicKind::Unknown);
    assert(cls.scope == TrackTransitionPublicScope::Unknown);
    std::cout << "PASS: test_track_transition_public_classification_default_construction" << std::endl;
}
