#pragma once

#include "p2_public_surface_observation_envelope.h"
#include "playback_p2_public_surface_observation.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationRecord {
    P2PublicSurfaceObservationEnvelope envelope{};
    PlaybackP2PublicSurfaceObservation observation{};
};

} // namespace kivo::playback::p2_public_surface_observation
