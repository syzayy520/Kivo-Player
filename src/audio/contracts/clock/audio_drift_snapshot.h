#pragma once
#include "../renderer/audio_renderer_id.h"
#include "core/clock/observation/drift_observation.h"
namespace kivo::playback::audio {
struct AudioDriftSnapshot {
    kivo::playback::clock::DriftObservation observation{};
    AudioRendererId renderer_id{};
};
}
