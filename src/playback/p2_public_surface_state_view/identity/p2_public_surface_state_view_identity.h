#pragma once

#include "p2_public_surface_state_view_id.h"
#include "p2_public_surface_state_view_sequence_id.h"
#include "p2_public_surface_state_view_generation.h"

namespace kivo::playback::p2_public_surface_state_view {

struct P2PublicSurfaceStateViewIdentity {
    P2PublicSurfaceStateViewId view_id{};
    P2PublicSurfaceStateViewSequenceId sequence_id{};
    P2PublicSurfaceStateViewGeneration generation{};

    bool operator==(const P2PublicSurfaceStateViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_state_view
