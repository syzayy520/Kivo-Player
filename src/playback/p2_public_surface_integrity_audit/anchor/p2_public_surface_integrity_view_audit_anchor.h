#pragma once

#include "playback/p2_public_surface_integrity_view/identity/p2_public_surface_integrity_view_identity.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityViewAuditAnchor {
    kivo::playback::p2_public_surface_integrity_view::P2PublicSurfaceIntegrityViewIdentity integrity_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
