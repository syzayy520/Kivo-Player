#pragma once

#include "../identity/p2_public_surface_retention_view_identity.h"
#include "p2_public_surface_retention_view_status.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfaceRetentionViewOutcome {
    P2PublicSurfaceRetentionViewIdentity identity{};
    P2PublicSurfaceRetentionViewStatus status{P2PublicSurfaceRetentionViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceRetentionViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_view
