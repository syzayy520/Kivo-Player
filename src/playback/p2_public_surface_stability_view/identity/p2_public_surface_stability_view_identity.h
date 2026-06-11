#pragma once

#include "p2_public_surface_stability_view_id.h"
#include "p2_public_surface_stability_view_sequence_id.h"
#include "p2_public_surface_stability_view_generation.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceStabilityViewIdentity {
    P2PublicSurfaceStabilityViewId view_id{};
    P2PublicSurfaceStabilityViewSequenceId sequence_id{};
    P2PublicSurfaceStabilityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceStabilityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_view
