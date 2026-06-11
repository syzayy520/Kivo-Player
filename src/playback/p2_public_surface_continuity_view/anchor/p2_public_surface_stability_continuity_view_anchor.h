#pragma once

#include "playback/p2_public_surface_stability_audit/identity/p2_public_surface_stability_audit_identity.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceStabilityContinuityViewAnchor {
    kivo::playback::p2_public_surface_stability_audit::P2PublicSurfaceStabilityAuditIdentity stability_identity{};
};

} // namespace kivo::playback::p2_public_surface_continuity_view
