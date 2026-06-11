#pragma once

#include "p2_public_surface_activation_audit_envelope.h"
#include "playback_p2_public_surface_activation_audit.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationAuditRecord {
    P2PublicSurfaceActivationAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceActivationAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_activation_audit
