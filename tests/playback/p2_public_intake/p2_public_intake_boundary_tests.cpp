#include <cassert>
#include <iostream>

#include "playback/p2_public_intake/identity/p2_public_intake_identity.h"
#include "playback/p2_public_intake/anchor/p1_closure_intake_anchor.h"
#include "playback/p2_public_intake/intake/playback_p2_public_intake.h"
#include "playback/p2_public_intake/outcome/p2_public_intake_outcome.h"

using namespace kivo::playback::p2_public_intake;

void test_p2_public_intake_boundary_cross_family() {
    P1ClosureIntakeAnchor anchor{};
    anchor.closure_identity.audit_id = kivo::playback::p1_public_surface_closure_audit::P1PublicSurfaceClosureAuditId{123};
    assert(anchor.closure_identity.audit_id.value == 123);
    PlaybackP2PublicIntake intake{
        .identity = P2PublicIntakeIdentity{.intake_id = P2PublicIntakeId{1}},
        .anchors = P2PublicIntakeAnchorSet{.closure_anchor = anchor},
        .classification = P2PublicIntakeClassification{.kind = P2PublicIntakeKind::SurfaceOpen, .scope = P2PublicIntakeScope::IntakeBoundary}
    };
    assert(intake.identity.intake_id.value == 1);
    assert(intake.anchors.closure_anchor.closure_identity.audit_id.value == 123);
    assert(intake.classification.kind == P2PublicIntakeKind::SurfaceOpen);
    assert(intake.classification.scope == P2PublicIntakeScope::IntakeBoundary);
    P2PublicIntakeOutcome outcome{.identity = P2PublicIntakeIdentity{.intake_id = P2PublicIntakeId{42}}, .status = P2PublicIntakeStatus::Recorded};
    assert(outcome.identity.intake_id.value == 42);
    assert(outcome.status == P2PublicIntakeStatus::Recorded);
    std::cout << "PASS: test_p2_public_intake_boundary_cross_family" << std::endl;
}
