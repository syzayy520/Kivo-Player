#pragma once

#include "p2_public_surface_continuity_view_id.h"
#include "p2_public_surface_continuity_view_sequence_id.h"
#include "p2_public_surface_continuity_view_generation.h"

namespace kivo::playback::p2_public_surface_continuity_view {

struct P2PublicSurfaceContinuityViewIdentity {
    P2PublicSurfaceContinuityViewId view_id{};
    P2PublicSurfaceContinuityViewSequenceId sequence_id{};
    P2PublicSurfaceContinuityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceContinuityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_continuity_view
