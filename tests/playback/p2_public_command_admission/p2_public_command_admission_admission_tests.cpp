#include <cassert>
#include <iostream>

#include "playback/p2_public_command_admission/admission/playback_p2_public_command_admission.h"
#include "playback/p2_public_command_admission/admission/p2_public_command_admission_candidate.h"
#include "playback/p2_public_command_admission/admission/p2_public_command_admission_envelope.h"
#include "playback/p2_public_command_admission/admission/p2_public_command_admission_record.h"

using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_command_admission_admission_default_construction() {
    P2PublicCommandAdmissionCandidate candidate{};
    assert(candidate.identity.admission_id.value == 0);
    assert(candidate.anchors.intake_anchor.intake_identity.intake_id.value == 0);
    assert(candidate.classification.kind == P2PublicCommandAdmissionKind::Unknown);
    PlaybackP2PublicCommandAdmission admission{};
    assert(admission.identity.admission_id.value == 0);
    P2PublicCommandAdmissionEnvelope envelope{};
    assert(envelope.identity.admission_id.value == 0);
    P2PublicCommandAdmissionRecord record{};
    assert(record.envelope.identity.admission_id.value == 0);
    assert(record.admission.identity.admission_id.value == 0);
    std::cout << "PASS: test_p2_public_command_admission_admission_default_construction" << std::endl;
}
