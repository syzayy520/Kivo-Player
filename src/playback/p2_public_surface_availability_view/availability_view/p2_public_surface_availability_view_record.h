#pragma once

#include "p2_public_surface_availability_view_envelope.h"
#include "playback_p2_public_surface_availability_view.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewRecord {
    P2PublicSurfaceAvailabilityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceAvailabilityView view{};
};

} // namespace kivo::playback::p2_public_surface_availability_view
