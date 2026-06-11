#pragma once

#include "p2_public_surface_observation_id.h"
#include "p2_public_surface_observation_sequence_id.h"
#include "p2_public_surface_observation_generation.h"

namespace kivo::playback::p2_public_surface_observation {

struct P2PublicSurfaceObservationIdentity {
    P2PublicSurfaceObservationId observation_id{};
    P2PublicSurfaceObservationSequenceId sequence_id{};
    P2PublicSurfaceObservationGeneration generation{};

    bool operator==(const P2PublicSurfaceObservationIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_observation
