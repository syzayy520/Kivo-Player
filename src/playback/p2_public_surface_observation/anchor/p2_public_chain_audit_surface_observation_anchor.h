#pragma once

#include "playback/p2_public_chain_audit/identity/p2_public_chain_audit_identity.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicChainAuditSurfaceObservationAnchor {
    kivo::playback::p2_public_chain_audit::P2PublicChainAuditIdentity audit_identity{};
};

} // namespace kivo::playback::p2_public_surface_observation
