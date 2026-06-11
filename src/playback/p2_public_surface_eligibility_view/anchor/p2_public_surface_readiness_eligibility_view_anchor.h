#pragma once

#include "playback/p2_public_surface_readiness_audit/identity/p2_public_surface_readiness_audit_identity.h"

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceReadinessEligibilityViewAnchor {
    kivo::playback::p2_public_surface_readiness_audit::P2PublicSurfaceReadinessAuditIdentity readiness_identity{};
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
