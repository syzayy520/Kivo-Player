#include <cassert>
#include <iostream>

#include "playback/p2_public_readback/identity/p2_public_readback_identity.h"
#include "playback/p2_public_readback/anchor/p2_public_command_admission_readback_anchor.h"
#include "playback/p2_public_readback/readback/playback_p2_public_readback.h"
#include "playback/p2_public_readback/outcome/p2_public_readback_outcome.h"

using namespace kivo::playback::p2_public_readback;

void test_p2_public_readback_boundary_cross_family() {
    P2PublicCommandAdmissionReadbackAnchor anchor{};
    anchor.admission_identity.admission_id = kivo::playback::p2_public_command_admission::P2PublicCommandAdmissionId{123};
    assert(anchor.admission_identity.admission_id.value == 123);
    PlaybackP2PublicReadback readback{
        .identity = P2PublicReadbackIdentity{.readback_id = P2PublicReadbackId{1}},
        .anchors = P2PublicReadbackAnchorSet{.admission_anchor = anchor},
        .classification = P2PublicReadbackClassification{.kind = P2PublicReadbackKind::SurfaceSnapshot, .scope = P2PublicReadbackScope::ReadbackBoundary}
    };
    assert(readback.identity.readback_id.value == 1);
    assert(readback.anchors.admission_anchor.admission_identity.admission_id.value == 123);
    assert(readback.classification.kind == P2PublicReadbackKind::SurfaceSnapshot);
    assert(readback.classification.scope == P2PublicReadbackScope::ReadbackBoundary);
    P2PublicReadbackOutcome outcome{.identity = P2PublicReadbackIdentity{.readback_id = P2PublicReadbackId{42}}, .status = P2PublicReadbackStatus::Recorded};
    assert(outcome.identity.readback_id.value == 42);
    assert(outcome.status == P2PublicReadbackStatus::Recorded);
    std::cout << "PASS: test_p2_public_readback_boundary_cross_family" << std::endl;
}
