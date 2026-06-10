#pragma once
#include "audio_endpoint_id.h"
#include "audio_endpoint_role.h"
namespace kivo::playback::audio {
struct AudioEndpointIdentity {
    AudioEndpointId id{};
    AudioEndpointRole role{AudioEndpointRole::Unknown};
};
}
