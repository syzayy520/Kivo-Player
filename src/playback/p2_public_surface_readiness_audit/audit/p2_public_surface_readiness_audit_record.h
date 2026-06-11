#pragma once

#include "p2_public_surface_readiness_audit_envelope.h"
#include "playback_p2_public_surface_readiness_audit.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditRecord {
    P2PublicSurfaceReadinessAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceReadinessAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
