#pragma once

#include "p2_public_surface_durability_audit_envelope.h"
#include "playback_p2_public_surface_durability_audit.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityAuditRecord {
    P2PublicSurfaceDurabilityAuditEnvelope envelope{};
    PlaybackP2PublicSurfaceDurabilityAudit audit{};
};

} // namespace kivo::playback::p2_public_surface_durability_audit
