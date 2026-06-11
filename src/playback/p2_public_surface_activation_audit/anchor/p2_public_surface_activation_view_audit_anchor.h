#pragma once

#include "playback/p2_public_surface_activation_view/identity/p2_public_surface_activation_view_identity.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationViewAuditAnchor {
    kivo::playback::p2_public_surface_activation_view::P2PublicSurfaceActivationViewIdentity activation_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_activation_audit
