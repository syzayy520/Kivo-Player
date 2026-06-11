#pragma once
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_identity.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelineUserStatusSurfaceReadAnchor {
    kivo::playback::timeline_user_status_surface::TimelineUserStatusSurfaceIdentity user_status_surface_identity{};
};
}
