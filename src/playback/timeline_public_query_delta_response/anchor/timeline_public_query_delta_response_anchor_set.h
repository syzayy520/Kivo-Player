#pragma once

#include "timeline_public_query_delta_response_query_delta_anchor.h"
#include "timeline_public_query_delta_response_response_anchor.h"
#include "p2_public_surface_final_audit_query_delta_response_anchor.h"

namespace kivo::playback::timeline_public_query_delta_response {

struct TimelinePublicQueryDeltaResponseAnchorSet {
    TimelinePublicQueryDeltaResponseQueryDeltaAnchor query_delta_anchor{};
    TimelinePublicQueryDeltaResponseResponseAnchor response_anchor{};
    P2PublicSurfaceFinalAuditQueryDeltaResponseAnchor final_audit_anchor{};
};

} // namespace kivo::playback::timeline_public_query_delta_response
