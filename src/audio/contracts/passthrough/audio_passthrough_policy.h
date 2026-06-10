#pragma once
#include "audio_passthrough_mode.h"
namespace kivo::playback::audio {
struct AudioPassthroughPolicy {
    AudioPassthroughMode mode{AudioPassthroughMode::Unknown};
};
}
