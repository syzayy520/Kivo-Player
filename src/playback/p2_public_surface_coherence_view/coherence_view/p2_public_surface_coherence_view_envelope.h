#pragma once

#include "../identity/p2_public_surface_coherence_view_identity.h"
#include "../anchor/p2_public_surface_coherence_view_anchor_set.h"
#include "../classification/p2_public_surface_coherence_view_classification.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewEnvelope {
    P2PublicSurfaceCoherenceViewIdentity identity{};
    P2PublicSurfaceCoherenceViewAnchorSet anchors{};
    P2PublicSurfaceCoherenceViewClassification classification{};
};

} // namespace kivo::playback::p2_public_surface_coherence_view
