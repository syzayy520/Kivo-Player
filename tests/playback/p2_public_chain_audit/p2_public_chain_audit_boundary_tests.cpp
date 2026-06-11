#include <cassert>
#include <iostream>

#include "playback/p2_public_chain_audit/identity/p2_public_chain_audit_identity.h"
#include "playback/p2_public_chain_audit/anchor/p2_public_completion_chain_audit_anchor.h"
#include "playback/p2_public_chain_audit/audit/playback_p2_public_chain_audit.h"
#include "playback/p2_public_chain_audit/outcome/p2_public_chain_audit_outcome.h"

using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_chain_audit_boundary_cross_family() {
    P2PublicCompletionChainAuditAnchor anchor{};
    anchor.completion_identity.completion_id = kivo::playback::p2_public_completion::P2PublicCompletionId{123};
    assert(anchor.completion_identity.completion_id.value == 123);
    PlaybackP2PublicChainAudit audit{
        .identity = P2PublicChainAuditIdentity{.audit_id = P2PublicChainAuditId{1}},
        .anchors = P2PublicChainAuditAnchorSet{.completion_anchor = anchor},
        .classification = P2PublicChainAuditClassification{.kind = P2PublicChainAuditKind::ChainClosed, .scope = P2PublicChainAuditScope::P2Chain}
    };
    assert(audit.identity.audit_id.value == 1);
    assert(audit.anchors.completion_anchor.completion_identity.completion_id.value == 123);
    assert(audit.classification.kind == P2PublicChainAuditKind::ChainClosed);
    assert(audit.classification.scope == P2PublicChainAuditScope::P2Chain);
    P2PublicChainAuditOutcome outcome{.identity = P2PublicChainAuditIdentity{.audit_id = P2PublicChainAuditId{42}}, .status = P2PublicChainAuditStatus::Recorded};
    assert(outcome.identity.audit_id.value == 42);
    assert(outcome.status == P2PublicChainAuditStatus::Recorded);
    std::cout << "PASS: test_p2_public_chain_audit_boundary_cross_family" << std::endl;
}
