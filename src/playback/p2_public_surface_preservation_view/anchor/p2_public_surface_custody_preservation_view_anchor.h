#pragma once

#include "playback/p2_public_surface_custody_view/identity/p2_public_surface_custody_view_identity.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfaceCustodyPreservationViewAnchor {
    kivo::playback::p2_public_surface_custody_view::P2PublicSurfaceCustodyViewIdentity custody_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_preservation_view
