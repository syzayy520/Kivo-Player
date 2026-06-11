#pragma once

#include "p2_public_chain_audit_kind.h"
#include "p2_public_chain_audit_scope.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditClassification {
    P2PublicChainAuditKind kind{P2PublicChainAuditKind::Unknown};
    P2PublicChainAuditScope scope{P2PublicChainAuditScope::Unknown};

    bool operator==(const P2PublicChainAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_chain_audit
