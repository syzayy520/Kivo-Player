#pragma once

#include "p2_public_surface_availability_view_id.h"
#include "p2_public_surface_availability_view_sequence_id.h"
#include "p2_public_surface_availability_view_generation.h"

namespace kivo::playback::p2_public_surface_availability_view {

struct P2PublicSurfaceAvailabilityViewIdentity {
    P2PublicSurfaceAvailabilityViewId view_id{};
    P2PublicSurfaceAvailabilityViewSequenceId sequence_id{};
    P2PublicSurfaceAvailabilityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceAvailabilityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_availability_view
