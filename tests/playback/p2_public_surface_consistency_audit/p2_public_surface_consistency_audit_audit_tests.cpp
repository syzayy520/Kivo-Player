#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_consistency_audit/audit/playback_p2_public_surface_consistency_audit.h"
#include "playback/p2_public_surface_consistency_audit/audit/p2_public_surface_consistency_audit_candidate.h"
#include "playback/p2_public_surface_consistency_audit/audit/p2_public_surface_consistency_audit_envelope.h"
#include "playback/p2_public_surface_consistency_audit/audit/p2_public_surface_consistency_audit_record.h"

using namespace kivo::playback::p2_public_surface_consistency_audit;

void test_p2_public_surface_consistency_audit_audit_default_construction() {
    P2PublicSurfaceConsistencyAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.progress_view_anchor.progress_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceConsistencyAuditKind::Unknown);
    PlaybackP2PublicSurfaceConsistencyAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceConsistencyAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceConsistencyAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_consistency_audit_audit_default_construction" << std::endl;
}
