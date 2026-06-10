#pragma once
#include "../renderer/audio_renderer_id.h"
#include "core/clock/clock_domains/clock_domain.h"
namespace kivo::playback::audio {
struct AudioClockBinding {
    kivo::playback::clock::ClockDomain domain{kivo::playback::clock::ClockDomain::Unknown};
    AudioRendererId renderer_id{};
};
}
