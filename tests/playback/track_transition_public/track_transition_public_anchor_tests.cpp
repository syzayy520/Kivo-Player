#include <cassert>
#include <iostream>

#include "playback/track_transition_public/anchor/buffering_public_track_transition_anchor.h"
#include "playback/track_transition_public/anchor/track_transition_public_anchor_set.h"

using namespace kivo::playback::track_transition_public;
using namespace kivo::playback::buffering_public;

void test_track_transition_public_anchor_default_construction() {
    BufferingPublicTrackTransitionAnchor anchor{};
    assert(anchor.buffering_identity.buffering_id.value == 0);
    anchor.buffering_identity.buffering_id = BufferingPublicId{123};
    assert(anchor.buffering_identity.buffering_id.value == 123);
    TrackTransitionPublicAnchorSet anchor_set{};
    assert(anchor_set.buffering_anchor.buffering_identity.buffering_id.value == 0);
    std::cout << "PASS: test_track_transition_public_anchor_default_construction" << std::endl;
}
