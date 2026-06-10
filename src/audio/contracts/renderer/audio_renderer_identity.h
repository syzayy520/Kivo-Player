#pragma once
#include "audio_renderer_id.h"
#include "audio_renderer_role.h"
namespace kivo::playback::audio {
struct AudioRendererIdentity {
    AudioRendererId id{};
    AudioRendererRole role{AudioRendererRole::Unknown};
};
}
