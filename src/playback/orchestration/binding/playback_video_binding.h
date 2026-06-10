#pragma once
#include "../session/playback_session_id.h"
#include "render/contracts/target/render_target_id.h"
namespace kivo::playback::orchestration {
struct PlaybackVideoBinding {
    PlaybackSessionId session_id{};
    kivo::playback::render::RenderTargetId target_id{};
};
}
