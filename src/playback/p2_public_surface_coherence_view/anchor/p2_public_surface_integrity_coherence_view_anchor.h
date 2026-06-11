#pragma once

#include "playback/p2_public_surface_integrity_audit/identity/p2_public_surface_integrity_audit_identity.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceIntegrityCoherenceViewAnchor {
    kivo::playback::p2_public_surface_integrity_audit::P2PublicSurfaceIntegrityAuditIdentity integrity_identity{};
};

} // namespace kivo::playback::p2_public_surface_coherence_view
