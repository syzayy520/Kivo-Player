#pragma once

#include "p2_public_surface_coherence_view_envelope.h"
#include "playback_p2_public_surface_coherence_view.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewRecord {
    P2PublicSurfaceCoherenceViewEnvelope envelope{};
    PlaybackP2PublicSurfaceCoherenceView view{};
};

} // namespace kivo::playback::p2_public_surface_coherence_view
