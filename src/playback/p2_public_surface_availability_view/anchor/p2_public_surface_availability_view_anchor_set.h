#pragma once

#include "p2_public_surface_consistency_availability_view_anchor.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewAnchorSet {
    P2PublicSurfaceConsistencyAvailabilityViewAnchor consistency_anchor{};
};

} // namespace kivo::playback::p2_public_surface_availability_view
