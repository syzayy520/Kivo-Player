#include <cassert>
#include <iostream>

#include "playback/p2_public_chain_audit/anchor/p2_public_completion_chain_audit_anchor.h"
#include "playback/p2_public_chain_audit/anchor/p2_public_chain_audit_anchor_set.h"

using namespace kivo::playback::p2_public_chain_audit;
using namespace kivo::playback::p2_public_completion;

void test_p2_public_chain_audit_anchor_default_construction() {
    P2PublicCompletionChainAuditAnchor anchor{};
    assert(anchor.completion_identity.completion_id.value == 0);
    anchor.completion_identity.completion_id = P2PublicCompletionId{123};
    assert(anchor.completion_identity.completion_id.value == 123);
    P2PublicChainAuditAnchorSet anchor_set{};
    assert(anchor_set.completion_anchor.completion_identity.completion_id.value == 0);
    std::cout << "PASS: test_p2_public_chain_audit_anchor_default_construction" << std::endl;
}
