#pragma once

#include "playback/timeline_public_response/identity/timeline_public_response_identity.h"

namespace kivo::playback::timeline_public_surface_boundary {

struct TimelinePublicResponseSurfaceBoundaryAnchor {
    kivo::playback::timeline_public_response::TimelinePublicResponseIdentity response_identity{};
};

} // namespace kivo::playback::timeline_public_surface_boundary
