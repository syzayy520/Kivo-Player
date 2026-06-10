#pragma once
#include "memory/handle/surface_handle.h"
#include "render_frame_id.h"
namespace kivo::playback::render {
struct RenderFrameSurface {
    RenderFrameId frame_id{};
    kivo::playback::memory::SurfaceHandle surface{};
};
}
