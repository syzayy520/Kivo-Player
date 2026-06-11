#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_retention_audit/audit/playback_p2_public_surface_retention_audit.h"
#include "playback/p2_public_surface_retention_audit/audit/p2_public_surface_retention_audit_candidate.h"
#include "playback/p2_public_surface_retention_audit/audit/p2_public_surface_retention_audit_envelope.h"
#include "playback/p2_public_surface_retention_audit/audit/p2_public_surface_retention_audit_record.h"

using namespace kivo::playback::p2_public_surface_retention_audit;

void test_p2_public_surface_retention_audit_audit_default_construction() {
    P2PublicSurfaceRetentionAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.retention_view_anchor.retention_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceRetentionAuditKind::Unknown);
    PlaybackP2PublicSurfaceRetentionAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceRetentionAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceRetentionAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_retention_audit_audit_default_construction" << std::endl;
}
