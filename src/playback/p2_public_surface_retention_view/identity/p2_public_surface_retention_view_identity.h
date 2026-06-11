#pragma once

#include "p2_public_surface_retention_view_id.h"
#include "p2_public_surface_retention_view_sequence_id.h"
#include "p2_public_surface_retention_view_generation.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfaceRetentionViewIdentity {
    P2PublicSurfaceRetentionViewId view_id{};
    P2PublicSurfaceRetentionViewSequenceId sequence_id{};
    P2PublicSurfaceRetentionViewGeneration generation{};

    bool operator==(const P2PublicSurfaceRetentionViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_view
