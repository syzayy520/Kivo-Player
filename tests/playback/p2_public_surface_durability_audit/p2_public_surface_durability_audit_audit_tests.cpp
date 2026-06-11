#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_durability_audit/audit/playback_p2_public_surface_durability_audit.h"
#include "playback/p2_public_surface_durability_audit/audit/p2_public_surface_durability_audit_candidate.h"
#include "playback/p2_public_surface_durability_audit/audit/p2_public_surface_durability_audit_envelope.h"
#include "playback/p2_public_surface_durability_audit/audit/p2_public_surface_durability_audit_record.h"

using namespace kivo::playback::p2_public_surface_durability_audit;

void test_p2_public_surface_durability_audit_audit_default_construction() {
    P2PublicSurfaceDurabilityAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.durability_view_anchor.durability_view_identity.view_id.value == 0);
    assert(candidate.classification.kind == P2PublicSurfaceDurabilityAuditKind::Unknown);
    PlaybackP2PublicSurfaceDurabilityAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicSurfaceDurabilityAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicSurfaceDurabilityAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_surface_durability_audit_audit_default_construction" << std::endl;
}
