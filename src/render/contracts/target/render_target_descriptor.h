#pragma once
#include "render_target_id.h"
#include "format/contracts/video/pixel_format_descriptor.h"
#include "format/contracts/color/color_space_descriptor.h"
namespace kivo::playback::render {
struct RenderTargetDescriptor {
    RenderTargetId target_id{};
    uint32_t width{0};
    uint32_t height{0};
    kivo::playback::format::PixelFormatDescriptor pixel_format_hint{};
    kivo::playback::format::ColorSpaceDescriptor color_space_hint{};
};
}
