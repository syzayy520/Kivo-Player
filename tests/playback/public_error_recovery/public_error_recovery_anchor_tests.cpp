#include <cassert>
#include <iostream>

#include "playback/public_error_recovery/anchor/end_of_stream_public_recovery_anchor.h"
#include "playback/public_error_recovery/anchor/public_error_recovery_anchor_set.h"

using namespace kivo::playback::public_error_recovery;
using namespace kivo::playback::end_of_stream_public;

void test_public_error_recovery_anchor_default_construction() {
    EndOfStreamPublicRecoveryAnchor anchor{};
    assert(anchor.end_identity.end_id.value == 0);
    anchor.end_identity.end_id = EndOfStreamPublicId{123};
    assert(anchor.end_identity.end_id.value == 123);
    PublicErrorRecoveryAnchorSet anchor_set{};
    assert(anchor_set.end_anchor.end_identity.end_id.value == 0);
    std::cout << "PASS: test_public_error_recovery_anchor_default_construction" << std::endl;
}
