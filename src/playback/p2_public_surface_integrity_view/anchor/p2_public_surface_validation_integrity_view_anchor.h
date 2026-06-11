#pragma once

#include "playback/p2_public_surface_validation_view/identity/p2_public_surface_validation_view_identity.h"

namespace kivo::playback::p2_public_surface_integrity_view {

struct P2PublicSurfaceValidationIntegrityViewAnchor {
    kivo::playback::p2_public_surface_validation_view::P2PublicSurfaceValidationViewIdentity validation_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_integrity_view
