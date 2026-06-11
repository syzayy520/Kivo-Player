#pragma once

#include "../identity/p2_public_chain_audit_identity.h"
#include "p2_public_chain_audit_status.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditOutcome {
    P2PublicChainAuditIdentity identity{};
    P2PublicChainAuditStatus status{P2PublicChainAuditStatus::Unknown};

    bool operator==(const P2PublicChainAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_chain_audit
