#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_activation_audit/audit/playback_p2_public_surface_activation_audit.h"
#include "playback/p2_public_surface_activation_audit/audit/p2_public_surface_activation_audit_candidate.h"
#include "playback/p2_public_surface_activation_audit/audit/p2_public_surface_activation_audit_envelope.h"
#include "playback/p2_public_surface_activation_audit/audit/p2_public_surface_activation_audit_record.h"

using namespace kivo::playback::p2_public_surface_activation_audit;

void test_p2_public_surface_activation_audit_audit_default_construction() {
    P2PublicSurfaceActivationAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.activation_view_anchor.activation_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceActivationAuditKind::Unknown);
    PlaybackP2PublicSurfaceActivationAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceActivationAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceActivationAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_activation_audit_audit_default_construction" << std::endl;
}
