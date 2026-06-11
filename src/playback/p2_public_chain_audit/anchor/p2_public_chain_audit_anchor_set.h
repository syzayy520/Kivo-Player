#pragma once

#include "p2_public_completion_chain_audit_anchor.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicChainAuditAnchorSet {
    P2PublicCompletionChainAuditAnchor completion_anchor{};
};

} // namespace kivo::playback::p2_public_chain_audit
