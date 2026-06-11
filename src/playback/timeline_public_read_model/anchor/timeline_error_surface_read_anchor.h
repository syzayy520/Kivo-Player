#pragma once
#include "playback/timeline_error_surface/identity/timeline_error_surface_identity.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelineErrorSurfaceReadAnchor {
    kivo::playback::timeline_error_surface::TimelineErrorSurfaceIdentity error_surface_identity{};
};
}
