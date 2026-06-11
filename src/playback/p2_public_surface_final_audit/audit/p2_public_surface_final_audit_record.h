#pragma once

#include "p2_public_surface_final_audit_envelope.h"
#include "playback_p2_public_surface_final_audit.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceFinalAuditRecord {
    P2PublicSurfaceFinalAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceFinalAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_final_audit
