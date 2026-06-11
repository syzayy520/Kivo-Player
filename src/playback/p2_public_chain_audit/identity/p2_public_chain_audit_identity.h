#pragma once

#include "p2_public_chain_audit_id.h"
#include "p2_public_chain_audit_sequence_id.h"
#include "p2_public_chain_audit_generation.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditIdentity {
    P2PublicChainAuditId audit_id{};
    P2PublicChainAuditSequenceId sequence_id{};
    P2PublicChainAuditGeneration generation{};

    bool operator==(const P2PublicChainAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_chain_audit
