#pragma once

#include "p2_public_surface_delta_id.h"
#include "p2_public_surface_delta_sequence_id.h"
#include "p2_public_surface_delta_generation.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaIdentity {
    P2PublicSurfaceDeltaId delta_id{};
    P2PublicSurfaceDeltaSequenceId sequence_id{};
    P2PublicSurfaceDeltaGeneration generation{};

    bool operator==(const P2PublicSurfaceDeltaIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_delta
