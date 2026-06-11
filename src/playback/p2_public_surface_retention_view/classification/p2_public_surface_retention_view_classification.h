#pragma once

#include "p2_public_surface_retention_view_kind.h"
#include "p2_public_surface_retention_view_scope.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfaceRetentionViewClassification {
    P2PublicSurfaceRetentionViewKind kind{P2PublicSurfaceRetentionViewKind::Unknown};
    P2PublicSurfaceRetentionViewScope scope{P2PublicSurfaceRetentionViewScope::Unknown};

    bool operator==(const P2PublicSurfaceRetentionViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_view
