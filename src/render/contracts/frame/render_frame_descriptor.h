#pragma once
#include "render_frame_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "format/contracts/video/pixel_format_descriptor.h"
#include "format/contracts/color/color_space_descriptor.h"
namespace kivo::playback::render {
struct RenderFrameDescriptor {
    RenderFrameId frame_id{};
    kivo::playback::timeline::MediaTimestamp timestamp{};
    kivo::playback::format::PixelFormatDescriptor pixel_format{};
    kivo::playback::format::ColorSpaceDescriptor color_space{};
};
}
