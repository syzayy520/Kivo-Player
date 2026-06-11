#pragma once

#include "playback/p2_public_surface_confirmation_view/identity/p2_public_surface_confirmation_view_identity.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationViewAuditAnchor {
    kivo::playback::p2_public_surface_confirmation_view::P2PublicSurfaceConfirmationViewIdentity confirmation_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
