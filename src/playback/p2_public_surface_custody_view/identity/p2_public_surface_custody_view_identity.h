#pragma once

#include "p2_public_surface_custody_view_id.h"
#include "p2_public_surface_custody_view_sequence_id.h"
#include "p2_public_surface_custody_view_generation.h"

namespace kivo::playback::p2_public_surface_custody_view {

struct P2PublicSurfaceCustodyViewIdentity {
    P2PublicSurfaceCustodyViewId view_id{};
    P2PublicSurfaceCustodyViewSequenceId sequence_id{};
    P2PublicSurfaceCustodyViewGeneration generation{};

    bool operator==(const P2PublicSurfaceCustodyViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_custody_view
