#pragma once
#include <cstdint>
#include "memory/handle/surface_handle.h"
namespace kivo::playback::render {
struct RenderFrameSurface {
    kivo::playback::memory::SurfaceHandle surface{};
    uint64_t width{0};
    uint64_t height{0};
};
}
