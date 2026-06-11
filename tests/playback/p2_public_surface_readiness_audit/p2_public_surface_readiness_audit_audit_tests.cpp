#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_readiness_audit/audit/playback_p2_public_surface_readiness_audit.h"
#include "playback/p2_public_surface_readiness_audit/audit/p2_public_surface_readiness_audit_candidate.h"
#include "playback/p2_public_surface_readiness_audit/audit/p2_public_surface_readiness_audit_envelope.h"
#include "playback/p2_public_surface_readiness_audit/audit/p2_public_surface_readiness_audit_record.h"

using namespace kivo::playback::p2_public_surface_readiness_audit;

void test_p2_public_surface_readiness_audit_audit_default_construction() {
    P2PublicSurfaceReadinessAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.readiness_view_anchor.readiness_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceReadinessAuditKind::Unknown);
    PlaybackP2PublicSurfaceReadinessAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceReadinessAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceReadinessAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_readiness_audit_audit_default_construction" << std::endl;
}
