#pragma once

#include "p2_public_surface_persistence_view_id.h"
#include "p2_public_surface_persistence_view_sequence_id.h"
#include "p2_public_surface_persistence_view_generation.h"

namespace kivo::playback::p2_public_surface_persistence_view {

struct P2PublicSurfacePersistenceViewIdentity {
    P2PublicSurfacePersistenceViewId view_id{};
    P2PublicSurfacePersistenceViewSequenceId sequence_id{};
    P2PublicSurfacePersistenceViewGeneration generation{};

    bool operator==(const P2PublicSurfacePersistenceViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_persistence_view
