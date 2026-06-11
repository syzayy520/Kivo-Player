#pragma once

#include "p2_public_surface_consistency_audit_envelope.h"
#include "playback_p2_public_surface_consistency_audit.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditRecord {
    P2PublicSurfaceConsistencyAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceConsistencyAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
