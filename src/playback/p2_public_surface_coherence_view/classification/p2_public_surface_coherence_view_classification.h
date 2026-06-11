#pragma once

#include "p2_public_surface_coherence_view_kind.h"
#include "p2_public_surface_coherence_view_scope.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewClassification {
    P2PublicSurfaceCoherenceViewKind kind{P2PublicSurfaceCoherenceViewKind::Unknown};
    P2PublicSurfaceCoherenceViewScope scope{P2PublicSurfaceCoherenceViewScope::Unknown};

    bool operator==(const P2PublicSurfaceCoherenceViewClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_coherence_view
