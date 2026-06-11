#pragma once

#include "p2_public_surface_preservation_view_id.h"
#include "p2_public_surface_preservation_view_sequence_id.h"
#include "p2_public_surface_preservation_view_generation.h"

namespace kivo::playback::p2_public_surface_preservation_view {

struct P2PublicSurfacePreservationViewIdentity {
    P2PublicSurfacePreservationViewId view_id{};
    P2PublicSurfacePreservationViewSequenceId sequence_id{};
    P2PublicSurfacePreservationViewGeneration generation{};

    bool operator==(const P2PublicSurfacePreservationViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_preservation_view
