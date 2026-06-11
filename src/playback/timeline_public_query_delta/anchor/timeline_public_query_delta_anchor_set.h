#pragma once

#include "timeline_public_query_delta_query_anchor.h"
#include "timeline_public_query_delta_delta_anchor.h"
#include "p2_public_surface_final_audit_query_delta_anchor.h"

namespace kivo::playback::timeline_public_query_delta {

struct TimelinePublicQueryDeltaAnchorSet {
    TimelinePublicQueryDeltaQueryAnchor query_anchor{};
    TimelinePublicQueryDeltaDeltaAnchor delta_anchor{};
    P2PublicSurfaceFinalAuditQueryDeltaAnchor final_audit_anchor{};
};

} // namespace kivo::playback::timeline_public_query_delta
