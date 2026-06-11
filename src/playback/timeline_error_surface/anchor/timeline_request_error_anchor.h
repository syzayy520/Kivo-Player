#pragma once
#include "playback/timeline_request/identity/timeline_request_identity.h"
namespace kivo::playback::timeline_error_surface {
struct TimelineRequestErrorAnchor {
    kivo::playback::timeline_request::TimelineRequestIdentity request_identity{};
};
}
