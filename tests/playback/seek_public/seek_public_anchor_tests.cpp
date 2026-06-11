#include <cassert>
#include <iostream>

#include "playback/seek_public/anchor/stream_selection_public_seek_anchor.h"
#include "playback/seek_public/anchor/seek_public_anchor_set.h"

using namespace kivo::playback::seek_public;
using namespace kivo::playback::stream_selection_public;

void test_seek_public_anchor_default_construction() {
    StreamSelectionPublicSeekAnchor anchor{};
    assert(anchor.selection_identity.selection_id.value == 0);
    anchor.selection_identity.selection_id = StreamSelectionPublicId{123};
    assert(anchor.selection_identity.selection_id.value == 123);
    SeekPublicAnchorSet anchor_set{};
    assert(anchor_set.selection_anchor.selection_identity.selection_id.value == 0);
    std::cout << "PASS: test_seek_public_anchor_default_construction" << std::endl;
}
