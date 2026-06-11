#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_final_audit/audit/playback_p2_public_surface_final_audit.h"
#include "playback/p2_public_surface_final_audit/audit/p2_public_surface_final_audit_candidate.h"
#include "playback/p2_public_surface_final_audit/audit/p2_public_surface_final_audit_envelope.h"
#include "playback/p2_public_surface_final_audit/audit/p2_public_surface_final_audit_record.h"

using namespace kivo::playback::p2_public_surface_final_audit;

void test_p2_public_surface_final_audit_audit_default_construction() {
    P2PublicSurfaceFinalAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.source_anchor.source_identity_token == 0);
    assert(candidate.classification.kind == P2PublicSurfaceFinalAuditKind::Unknown);
    PlaybackP2PublicSurfaceFinalAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceFinalAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceFinalAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_final_audit_audit_default_construction" << std::endl;
}
