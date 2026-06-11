#pragma once

#include "p2_public_surface_eligibility_view_envelope.h"
#include "playback_p2_public_surface_eligibility_view.h"

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewRecord {
    P2PublicSurfaceEligibilityViewEnvelope envelope{};
    PlaybackP2PublicSurfaceEligibilityView view{};
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
