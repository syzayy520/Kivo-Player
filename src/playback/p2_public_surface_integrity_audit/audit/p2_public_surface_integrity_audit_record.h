#pragma once

#include "p2_public_surface_integrity_audit_envelope.h"
#include "playback_p2_public_surface_integrity_audit.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditRecord {
    P2PublicSurfaceIntegrityAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceIntegrityAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
