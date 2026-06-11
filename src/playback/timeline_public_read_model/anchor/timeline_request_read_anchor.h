#pragma once
#include "playback/timeline_request/identity/timeline_request_identity.h"
namespace kivo::playback::timeline_public_read_model {
struct TimelineRequestReadAnchor {
    kivo::playback::timeline_request::TimelineRequestIdentity request_identity{};
};
}
