#include <cassert>
#include <iostream>

#include "playback/p2_public_command_admission/anchor/p2_public_intake_command_admission_anchor.h"
#include "playback/p2_public_command_admission/anchor/p2_public_command_admission_anchor_set.h"

using namespace kivo::playback::p2_public_command_admission;
using namespace kivo::playback::p2_public_intake;

void test_p2_public_command_admission_anchor_default_construction() {
    P2PublicIntakeCommandAdmissionAnchor anchor{};
    assert(anchor.intake_identity.intake_id.value == 0);
    anchor.intake_identity.intake_id = P2PublicIntakeId{123};
    assert(anchor.intake_identity.intake_id.value == 123);
    P2PublicCommandAdmissionAnchorSet anchor_set{};
    assert(anchor_set.intake_anchor.intake_identity.intake_id.value == 0);
    std::cout << "PASS: test_p2_public_command_admission_anchor_default_construction" << std::endl;
}
