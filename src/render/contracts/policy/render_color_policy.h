#pragma once
#include "format/contracts/color/color_space_descriptor.h"
namespace kivo::playback::render {
struct RenderColorPolicy {
    kivo::playback::format::ColorSpaceDescriptor output_color_space{};
    bool auto_convert{true};
};
}
