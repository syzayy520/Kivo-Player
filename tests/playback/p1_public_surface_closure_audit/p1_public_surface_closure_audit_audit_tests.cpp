#include <cassert>
#include <iostream>

#include "playback/p1_public_surface_closure_audit/audit/playback_p1_public_surface_closure_audit.h"
#include "playback/p1_public_surface_closure_audit/audit/p1_public_surface_closure_audit_candidate.h"
#include "playback/p1_public_surface_closure_audit/audit/p1_public_surface_closure_audit_envelope.h"
#include "playback/p1_public_surface_closure_audit/audit/p1_public_surface_closure_audit_record.h"

using namespace kivo::playback::p1_public_surface_closure_audit;

void test_p1_public_surface_closure_audit_audit_default_construction() {
    P1PublicSurfaceClosureAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.recovery_anchor.recovery_identity.recovery_id.value == 0);
    assert(candidate.classification.kind == P1PublicSurfaceClosureAuditKind::Unknown);
    PlaybackP1PublicSurfaceClosureAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P1PublicSurfaceClosureAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P1PublicSurfaceClosureAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p1_public_surface_closure_audit_audit_default_construction" << std::endl;
}
