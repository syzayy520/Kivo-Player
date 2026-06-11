#pragma once

#include "p2_public_surface_progress_consistency_audit_anchor.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditAnchorSet {
    P2PublicSurfaceProgressConsistencyAuditAnchor progress_view_anchor{};
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
