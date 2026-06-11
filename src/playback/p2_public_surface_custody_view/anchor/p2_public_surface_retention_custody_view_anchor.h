#pragma once

#include "playback/p2_public_surface_retention_audit/identity/p2_public_surface_retention_audit_identity.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceRetentionCustodyViewAnchor {
    kivo::playback::p2_public_surface_retention_audit::P2PublicSurfaceRetentionAuditIdentity retention_identity{};
};

} // namespace kivo::playback::p2_public_surface_custody_view
