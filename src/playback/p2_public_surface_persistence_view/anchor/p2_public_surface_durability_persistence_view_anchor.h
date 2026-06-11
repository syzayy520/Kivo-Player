#pragma once

#include "playback/p2_public_surface_durability_audit/identity/p2_public_surface_durability_audit_identity.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfaceDurabilityPersistenceViewAnchor {
    kivo::playback::p2_public_surface_durability_audit::P2PublicSurfaceDurabilityAuditIdentity durability_identity{};
};

} // namespace kivo::playback::p2_public_surface_persistence_view
