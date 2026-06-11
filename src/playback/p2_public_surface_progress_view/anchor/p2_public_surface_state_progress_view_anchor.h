#pragma once

#include "playback/p2_public_surface_state_view/identity/p2_public_surface_state_view_identity.h"

namespace kivo::playback::p2_public_surface_progress_view {

struct P2PublicSurfaceStateProgressViewAnchor {
    kivo::playback::p2_public_surface_state_view::P2PublicSurfaceStateViewIdentity state_view_identity{};
};

} // namespace kivo::playback::p2_public_surface_progress_view
