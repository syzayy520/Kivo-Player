#pragma once

#include "playback/p2_public_completion/identity/p2_public_completion_identity.h"

namespace kivo::playback::p2_public_chain_audit {

struct P2PublicCompletionChainAuditAnchor {
    kivo::playback::p2_public_completion::P2PublicCompletionIdentity completion_identity{};
};

} // namespace kivo::playback::p2_public_chain_audit
