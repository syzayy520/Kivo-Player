#pragma once
#include "playback/timeline_request/identity/timeline_request_identity.h"
namespace kivo::playback::timeline_user_status_surface {
struct TimelineRequestStatusAnchor {
    kivo::playback::timeline_request::TimelineRequestIdentity request_identity{};
};
}
