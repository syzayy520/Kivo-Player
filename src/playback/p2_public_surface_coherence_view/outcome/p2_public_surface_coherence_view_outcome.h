#pragma once

#include "../identity/p2_public_surface_coherence_view_identity.h"
#include "p2_public_surface_coherence_view_status.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewOutcome {
    P2PublicSurfaceCoherenceViewIdentity identity{};
    P2PublicSurfaceCoherenceViewStatus status{P2PublicSurfaceCoherenceViewStatus::Unknown};

    bool operator==(const P2PublicSurfaceCoherenceViewOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_coherence_view
