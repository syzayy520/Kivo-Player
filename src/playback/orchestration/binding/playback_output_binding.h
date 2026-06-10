#pragma once
#include "../session/playback_session_id.h"
#include "playback_device_binding.h"
#include "playback_audio_binding.h"
#include "playback_video_binding.h"
namespace kivo::playback::orchestration {
struct PlaybackOutputBinding {
    PlaybackSessionId session_id{};
    PlaybackDeviceBinding device{};
    PlaybackAudioBinding audio{};
    PlaybackVideoBinding video{};
};
}
