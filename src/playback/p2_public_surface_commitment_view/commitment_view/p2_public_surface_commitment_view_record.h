#pragma once

#include "p2_public_surface_commitment_view_envelope.h"
#include "playback_p2_public_surface_commitment_view.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceCommitmentViewRecord {
    P2PublicSurfaceCommitmentViewEnvelope envelope{};
    PlaybackP2PublicSurfaceCommitmentView view{};
};

} // namespace kivo::playback::p2_public_surface_commitment_view
