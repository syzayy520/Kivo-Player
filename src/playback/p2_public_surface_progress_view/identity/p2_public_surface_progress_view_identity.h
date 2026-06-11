#pragma once

#include "p2_public_surface_progress_view_id.h"
#include "p2_public_surface_progress_view_sequence_id.h"
#include "p2_public_surface_progress_view_generation.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceProgressViewIdentity {
    P2PublicSurfaceProgressViewId view_id{};
    P2PublicSurfaceProgressViewSequenceId sequence_id{};
    P2PublicSurfaceProgressViewGeneration generation{};

    bool operator==(const P2PublicSurfaceProgressViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_progress_view
