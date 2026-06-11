#pragma once

#include "p2_public_surface_retention_view_envelope.h"
#include "playback_p2_public_surface_retention_view.h"

namespace kivo::playback::p2_public_surface_retention_view {

struct P2PublicSurfaceRetentionViewRecord {
    P2PublicSurfaceRetentionViewEnvelope envelope{};
    PlaybackP2PublicSurfaceRetentionView view{};
};

} // namespace kivo::playback::p2_public_surface_retention_view
