#pragma once

#include "../identity/p2_public_chain_audit_identity.h"
#include "../anchor/p2_public_chain_audit_anchor_set.h"
#include "../classification/p2_public_chain_audit_classification.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditEnvelope {
    P2PublicChainAuditIdentity identity{};
    P2PublicChainAuditAnchorSet anchors{};
    P2PublicChainAuditClassification classification{};
};

} // namespace kivo::playback::p2_public_chain_audit
