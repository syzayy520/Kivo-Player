#pragma once

#include "p2_public_surface_coherence_view_id.h"
#include "p2_public_surface_coherence_view_sequence_id.h"
#include "p2_public_surface_coherence_view_generation.h"

namespace kivo::playback::p2_public_surface_coherence_view {

struct P2PublicSurfaceCoherenceViewIdentity {
    P2PublicSurfaceCoherenceViewId view_id{};
    P2PublicSurfaceCoherenceViewSequenceId sequence_id{};
    P2PublicSurfaceCoherenceViewGeneration generation{};

    bool operator==(const P2PublicSurfaceCoherenceViewIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_coherence_view
