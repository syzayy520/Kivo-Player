#pragma once

#include "playback/p2_public_surface_coherence_view/identity/p2_public_surface_coherence_view_identity.h"

namespace kivo::playback::p2_public_surface_stability_view {

struct P2PublicSurfaceCoherenceStabilityViewAnchor {
    kivo::playback::p2_public_surface_coherence_view::P2PublicSurfaceCoherenceViewIdentity coherence_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_stability_view
