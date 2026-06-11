#pragma once

#include "p1_public_surface_closure_audit_envelope.h"
#include "playback_p1_public_surface_closure_audit.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditRecord {
    P1PublicSurfaceClosureAuditEnvelope envelope{};
    PlaybackP1PublicSurfaceClosureAudit audit{};
};

} // namespace kivo::playback::p1_public_surface_closure_audit
