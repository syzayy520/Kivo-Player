#include <cassert>
#include <iostream>

#include "playback/buffering_public/anchor/seek_public_buffering_anchor.h"
#include "playback/buffering_public/anchor/buffering_public_anchor_set.h"

using namespace kivo::playback::buffering_public;
using namespace kivo::playback::seek_public;

void test_buffering_public_anchor_default_construction() {
    SeekPublicBufferingAnchor anchor{};
    assert(anchor.seek_identity.seek_id.value == 0);
    anchor.seek_identity.seek_id = SeekPublicId{123};
    assert(anchor.seek_identity.seek_id.value == 123);
    BufferingPublicAnchorSet anchor_set{};
    assert(anchor_set.seek_anchor.seek_identity.seek_id.value == 0);
    std::cout << "PASS: test_buffering_public_anchor_default_construction" << std::endl;
}
