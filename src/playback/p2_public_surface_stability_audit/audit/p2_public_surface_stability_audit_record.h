#pragma once

#include "p2_public_surface_stability_audit_envelope.h"
#include "playback_p2_public_surface_stability_audit.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditRecord {
    P2PublicSurfaceStabilityAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceStabilityAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_stability_audit
