#pragma once

#include "playback/p2_public_surface_durability_view/identity/p2_public_surface_durability_view_identity.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityViewAuditAnchor {
    kivo::playback::p2_public_surface_durability_view::P2PublicSurfaceDurabilityViewIdentity durability_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_durability_audit
