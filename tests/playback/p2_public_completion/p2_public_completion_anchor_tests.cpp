#include <cassert>
#include <iostream>

#include "playback/p2_public_completion/anchor/p2_public_readback_completion_anchor.h"
#include "playback/p2_public_completion/anchor/p2_public_completion_anchor_set.h"

using namespace kivo::playback::p2_public_completion;
using namespace kivo::playback::p2_public_readback;

void test_p2_public_completion_anchor_default_construction() {
    P2PublicReadbackCompletionAnchor anchor{};
    assert(anchor.readback_identity.readback_id.value == 0);
    anchor.readback_identity.readback_id = P2PublicReadbackId{123};
    assert(anchor.readback_identity.readback_id.value == 123);
    P2PublicCompletionAnchorSet anchor_set{};
    assert(anchor_set.readback_anchor.readback_identity.readback_id.value == 0);
    std::cout << "PASS: test_p2_public_completion_anchor_default_construction" << std::endl;
}
