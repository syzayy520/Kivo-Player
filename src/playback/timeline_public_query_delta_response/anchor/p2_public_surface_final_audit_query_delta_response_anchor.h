#pragma once

#include "playback/p2_public_surface_final_audit/identity/p2_public_surface_final_audit_identity.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct P2PublicSurfaceFinalAuditQueryDeltaResponseAnchor {
    kivo::playback::p2_public_surface_final_audit::P2PublicSurfaceFinalAuditIdentity final_audit_identity{};
};

} // namespace kivo::playback::timeline_public_query_delta_response
