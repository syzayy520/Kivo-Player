#pragma once

#include "p2_public_surface_retention_audit_envelope.h"
#include "playback_p2_public_surface_retention_audit.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditRecord {
    P2PublicSurfaceRetentionAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceRetentionAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_retention_audit
