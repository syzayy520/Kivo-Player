#pragma once

#include "p2_public_surface_readiness_view_id.h"
#include "p2_public_surface_readiness_view_sequence_id.h"
#include "p2_public_surface_readiness_view_generation.h"

namespace kivo::playback::p2_public_surface_readiness_view {

struct P2PublicSurfaceReadinessViewIdentity {
    P2PublicSurfaceReadinessViewId view_id{};
    P2PublicSurfaceReadinessViewSequenceId sequence_id{};
    P2PublicSurfaceReadinessViewGeneration generation{};

    bool operator==(const P2PublicSurfaceReadinessViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_view
