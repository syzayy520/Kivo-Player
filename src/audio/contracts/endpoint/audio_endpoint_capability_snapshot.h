#pragma once
#include "audio_endpoint_id.h"
#include "capability/contracts/requirement/capability_result.h"
#include "capability/contracts/negotiation/negotiation_result.h"
namespace kivo::playback::audio {
struct AudioEndpointCapabilitySnapshot {
    AudioEndpointId endpoint_id{};
    kivo::playback::capability::CapabilityResult capability_result{};
    kivo::playback::capability::NegotiationResult negotiation_result{};
};
}
