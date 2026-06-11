#pragma once

#include "playback/p2_public_surface_readiness_view/identity/p2_public_surface_readiness_view_identity.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessViewAuditAnchor {
    kivo::playback::p2_public_surface_readiness_view::P2PublicSurfaceReadinessViewIdentity readiness_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
