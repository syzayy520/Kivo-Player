#pragma once

#include "p2_public_surface_durability_view_id.h"
#include "p2_public_surface_durability_view_sequence_id.h"
#include "p2_public_surface_durability_view_generation.h"

namespace kivo::playback::p2_public_surface_durability_view {

struct P2PublicSurfaceDurabilityViewIdentity {
    P2PublicSurfaceDurabilityViewId view_id{};
    P2PublicSurfaceDurabilityViewSequenceId sequence_id{};
    P2PublicSurfaceDurabilityViewGeneration generation{};

    bool operator==(const P2PublicSurfaceDurabilityViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_view
