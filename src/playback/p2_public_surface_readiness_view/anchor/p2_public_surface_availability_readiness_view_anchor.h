#pragma once

#include "playback/p2_public_surface_availability_view/identity/p2_public_surface_availability_view_identity.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceAvailabilityReadinessViewAnchor {
    kivo::playback::p2_public_surface_availability_view::P2PublicSurfaceAvailabilityViewIdentity availability_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_readiness_view
