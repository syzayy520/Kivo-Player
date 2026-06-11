#include <cassert>
#include <iostream>

#include "playback/p2_public_chain_audit/audit/playback_p2_public_chain_audit.h"
#include "playback/p2_public_chain_audit/audit/p2_public_chain_audit_candidate.h"
#include "playback/p2_public_chain_audit/audit/p2_public_chain_audit_envelope.h"
#include "playback/p2_public_chain_audit/audit/p2_public_chain_audit_record.h"

using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_chain_audit_audit_default_construction() {
    P2PublicChainAuditCandidate candidate{};
    assert(candidate.identity.audit_id.value == 0);
    assert(candidate.anchors.completion_anchor.completion_identity.completion_id.value == 0);
    assert(candidate.classification.kind == P2PublicChainAuditKind::Unknown);
    PlaybackP2PublicChainAudit audit{};
    assert(audit.identity.audit_id.value == 0);
    P2PublicChainAuditEnvelope envelope{};
    assert(envelope.identity.audit_id.value == 0);
    P2PublicChainAuditRecord record{};
    assert(record.envelope.identity.audit_id.value == 0);
    assert(record.audit.identity.audit_id.value == 0);
    std::cout << "PASS: test_p2_public_chain_audit_audit_default_construction" << std::endl;
}
