#pragma once

#include "playback/p2_public_surface_consistency_audit/identity/p2_public_surface_consistency_audit_identity.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceConsistencyAvailabilityViewAnchor {
    kivo::playback::p2_public_surface_consistency_audit::P2PublicSurfaceConsistencyAuditIdentity consistency_identity{};
};

} // namespace kivo::playback::p2_public_surface_availability_view
