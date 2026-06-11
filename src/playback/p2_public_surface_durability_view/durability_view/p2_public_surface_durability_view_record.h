#pragma once

#include "p2_public_surface_durability_view_envelope.h"
#include "playback_p2_public_surface_durability_view.h"

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewRecord {
    P2PublicSurfaceDurabilityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceDurabilityView view{};
};

} // namespace kivo::playback::p2_public_surface_durability_view
