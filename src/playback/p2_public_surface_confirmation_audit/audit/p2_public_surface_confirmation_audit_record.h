#pragma once

#include "p2_public_surface_confirmation_audit_envelope.h"
#include "playback_p2_public_surface_confirmation_audit.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditRecord {
    P2PublicSurfaceConfirmationAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceConfirmationAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
