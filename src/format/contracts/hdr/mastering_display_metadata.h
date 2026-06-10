// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::format {
struct MasteringDisplayMetadata {
    float display_primaries_rx{0.0f}; float display_primaries_ry{0.0f};
    float display_primaries_gx{0.0f}; float display_primaries_gy{0.0f};
    float display_primaries_bx{0.0f}; float display_primaries_by{0.0f};
    float white_point_x{0.0f}; float white_point_y{0.0f};
    float max_luminance{0.0f}; float min_luminance{0.0f};
    bool present{false};
};
}
