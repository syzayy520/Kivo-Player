#pragma once

#include "playback/p2_public_surface_preservation_view/identity/p2_public_surface_preservation_view_identity.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceSourceFinalAnchor {
    kivo::playback::p2_public_surface_preservation_view::P2PublicSurfacePreservationViewIdentity preservation_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_final_audit
