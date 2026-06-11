#include <cassert>
#include <iostream>

#include "playback/p2_public_intake/intake/playback_p2_public_intake.h"
#include "playback/p2_public_intake/intake/p2_public_intake_candidate.h"
#include "playback/p2_public_intake/intake/p2_public_intake_envelope.h"
#include "playback/p2_public_intake/intake/p2_public_intake_record.h"

using namespace kivo::playback::p2_public_intake;

void test_p2_public_intake_intake_default_construction() {
    P2PublicIntakeCandidate candidate{};
    assert(candidate.identity.intake_id.value == 0);
    assert(candidate.anchors.closure_anchor.closure_identity.audit_id.value == 0);
    assert(candidate.classification.kind == P2PublicIntakeKind::Unknown);
    PlaybackP2PublicIntake intake{};
    assert(intake.identity.intake_id.value == 0);
    P2PublicIntakeEnvelope envelope{};
    assert(envelope.identity.intake_id.value == 0);
    P2PublicIntakeRecord record{};
    assert(record.envelope.identity.intake_id.value == 0);
    assert(record.intake.identity.intake_id.value == 0);
    std::cout << "PASS: test_p2_public_intake_intake_default_construction" << std::endl;
}
