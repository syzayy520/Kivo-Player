#pragma once

#include "playback/p2_public_surface_stability_view/identity/p2_public_surface_stability_view_identity.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityViewAuditAnchor {
    kivo::playback::p2_public_surface_stability_view::P2PublicSurfaceStabilityViewIdentity stability_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_stability_audit
