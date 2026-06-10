#pragma once
#include <cstdint>
#include "overlay_plane_id.h"
#include "overlay_plane_role.h"
#include "memory/handle/surface_handle.h"
#include "format/contracts/video/pixel_format_descriptor.h"
#include "format/contracts/color/color_space_descriptor.h"
namespace kivo::playback::subtitle {
struct OverlayPlaneDescriptor {
    OverlayPlaneId plane_id{};
    OverlayPlaneRole role{OverlayPlaneRole::Unknown};
    kivo::playback::memory::SurfaceHandle surface{};
    uint64_t width{0};
    uint64_t height{0};
    kivo::playback::format::PixelFormatDescriptor pixel_format{};
    kivo::playback::format::ColorSpaceDescriptor color_space{};
};
}
