#include <cassert>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/anchor/public_error_recovery_closure_audit_anchor.h"
#include "playback/p1_public_surface_closure_audit/anchor/p1_public_surface_closure_audit_anchor_set.h"

using namespace kivo::playback::p1_public_surface_closure_audit;
using namespace kivo::playback::public_error_recovery;

void test_p1_public_surface_closure_audit_anchor_default_construction() {
    PublicErrorRecoveryClosureAuditAnchor anchor{};
    assert(anchor.recovery_identity.recovery_id.value == 0);
    anchor.recovery_identity.recovery_id = PublicErrorRecoveryId{123};
    assert(anchor.recovery_identity.recovery_id.value == 123);
    P1PublicSurfaceClosureAuditAnchorSet anchor_set{};
    assert(anchor_set.recovery_anchor.recovery_identity.recovery_id.value == 0);
    std::cout << "PASS: test_p1_public_surface_closure_audit_anchor_default_construction" << std::endl;
}
