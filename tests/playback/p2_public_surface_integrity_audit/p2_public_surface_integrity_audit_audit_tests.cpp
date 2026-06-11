#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_integrity_audit/audit/playback_p2_public_surface_integrity_audit.h"
#include "playback/p2_public_surface_integrity_audit/audit/p2_public_surface_integrity_audit_candidate.h"
#include "playback/p2_public_surface_integrity_audit/audit/p2_public_surface_integrity_audit_envelope.h"
#include "playback/p2_public_surface_integrity_audit/audit/p2_public_surface_integrity_audit_record.h"

using namespace kivo::playback::p2_public_surface_integrity_audit;

void test_p2_public_surface_integrity_audit_audit_default_construction() {
    P2PublicSurfaceIntegrityAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.integrity_view_anchor.integrity_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceIntegrityAuditKind::Unknown);
    PlaybackP2PublicSurfaceIntegrityAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceIntegrityAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceIntegrityAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_integrity_audit_audit_default_construction" << std::endl;
}
