#pragma once

#include "playback/p2_public_surface_retention_view/identity/p2_public_surface_retention_view_identity.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionViewAuditAnchor {
    kivo::playback::p2_public_surface_retention_view::P2PublicSurfaceRetentionViewIdentity retention_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_retention_audit
