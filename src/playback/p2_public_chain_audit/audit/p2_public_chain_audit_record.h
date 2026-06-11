#pragma once

#include "p2_public_chain_audit_envelope.h"
#include "playback_p2_public_chain_audit.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditRecord {
    P2PublicChainAuditEnvelope envelope{};
    PlaybackP2PublicChainAudit audit{};
};

} // namespace kivo::playback::p2_public_chain_audit
