#include <cassert>
#include <iostream>

#include "playback/end_of_stream_public/anchor/track_transition_public_end_of_stream_anchor.h"
#include "playback/end_of_stream_public/anchor/end_of_stream_public_anchor_set.h"

using namespace kivo::playback::end_of_stream_public;
using namespace kivo::playback::track_transition_public;

void test_end_of_stream_public_anchor_default_construction() {
    TrackTransitionPublicEndOfStreamAnchor anchor{};
    assert(anchor.transition_identity.transition_id.value == 0);
    anchor.transition_identity.transition_id = TrackTransitionPublicId{123};
    assert(anchor.transition_identity.transition_id.value == 123);
    EndOfStreamPublicAnchorSet anchor_set{};
    assert(anchor_set.transition_anchor.transition_identity.transition_id.value == 0);
    std::cout << "PASS: test_end_of_stream_public_anchor_default_construction" << std::endl;
}
