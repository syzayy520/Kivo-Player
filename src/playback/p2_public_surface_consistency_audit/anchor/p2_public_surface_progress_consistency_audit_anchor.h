#pragma once

#include "playback/p2_public_surface_progress_view/identity/p2_public_surface_progress_view_identity.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceProgressConsistencyAuditAnchor {
    kivo::playback::p2_public_surface_progress_view::P2PublicSurfaceProgressViewIdentity progress_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
