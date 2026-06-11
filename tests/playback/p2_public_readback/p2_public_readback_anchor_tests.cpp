#include <cassert>
#include <iostream>

#include "playback/p2_public_readback/anchor/p2_public_command_admission_readback_anchor.h"
#include "playback/p2_public_readback/anchor/p2_public_readback_anchor_set.h"

using namespace kivo::playback::p2_public_readback;
using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_readback_anchor_default_construction() {
    P2PublicCommandAdmissionReadbackAnchor anchor{};
    assert(anchor.admission_identity.admission_id.value == 0);
    anchor.admission_identity.admission_id = P2PublicCommandAdmissionId{123};
    assert(anchor.admission_identity.admission_id.value == 123);
    P2PublicReadbackAnchorSet anchor_set{};
    assert(anchor_set.admission_anchor.admission_identity.admission_id.value == 0);
    std::cout << "PASS: test_p2_public_readback_anchor_default_construction" << std::endl;
}
