#pragma once
#include "../session/playback_session_id.h"
#include "audio/contracts/endpoint/audio_endpoint_id.h"
namespace kivo::playback::orchestration {
struct PlaybackAudioBinding {
    PlaybackSessionId session_id{};
    kivo::playback::audio::AudioEndpointId endpoint_id{};
};
}
