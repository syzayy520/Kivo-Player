#include <cassert>
#include <iostream>

#include "playback/p2_public_command_admission/identity/p2_public_command_admission_identity.h"
#include "playback/p2_public_command_admission/anchor/p2_public_intake_command_admission_anchor.h"
#include "playback/p2_public_command_admission/admission/playback_p2_public_command_admission.h"
#include "playback/p2_public_command_admission/outcome/p2_public_command_admission_outcome.h"

using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_command_admission_boundary_cross_family() {
    P2PublicIntakeCommandAdmissionAnchor anchor{};
    anchor.intake_identity.intake_id = kivo::playback::p2_public_intake::P2PublicIntakeId{123};
    assert(anchor.intake_identity.intake_id.value == 123);
    PlaybackP2PublicCommandAdmission admission{
        .identity = P2PublicCommandAdmissionIdentity{.admission_id = P2PublicCommandAdmissionId{1}},
        .anchors = P2PublicCommandAdmissionAnchorSet{.intake_anchor = anchor},
        .classification = P2PublicCommandAdmissionClassification{.kind = P2PublicCommandAdmissionKind::PlayIntent, .scope = P2PublicCommandAdmissionScope::CommandBoundary}
    };
    assert(admission.identity.admission_id.value == 1);
    assert(admission.anchors.intake_anchor.intake_identity.intake_id.value == 123);
    assert(admission.classification.kind == P2PublicCommandAdmissionKind::PlayIntent);
    assert(admission.classification.scope == P2PublicCommandAdmissionScope::CommandBoundary);
    P2PublicCommandAdmissionOutcome outcome{.identity = P2PublicCommandAdmissionIdentity{.admission_id = P2PublicCommandAdmissionId{42}}, .status = P2PublicCommandAdmissionStatus::Admitted};
    assert(outcome.identity.admission_id.value == 42);
    assert(outcome.status == P2PublicCommandAdmissionStatus::Admitted);
    std::cout << "PASS: test_p2_public_command_admission_boundary_cross_family" << std::endl;
}
