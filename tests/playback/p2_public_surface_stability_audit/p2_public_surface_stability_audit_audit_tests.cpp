#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_audit/audit/playback_p2_public_surface_stability_audit.h"
#include "playback/p2_public_surface_stability_audit/audit/p2_public_surface_stability_audit_candidate.h"
#include "playback/p2_public_surface_stability_audit/audit/p2_public_surface_stability_audit_envelope.h"
#include "playback/p2_public_surface_stability_audit/audit/p2_public_surface_stability_audit_record.h"

using namespace kivo::playback::p2_public_surface_stability_audit;

void test_p2_public_surface_stability_audit_audit_default_construction() {
    P2PublicSurfaceStabilityAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.stability_view_anchor.stability_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceStabilityAuditKind::Unknown);
    PlaybackP2PublicSurfaceStabilityAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceStabilityAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceStabilityAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_stability_audit_audit_default_construction" << std::endl;
}
