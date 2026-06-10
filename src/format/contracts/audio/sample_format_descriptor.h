// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::format {
struct SampleFormatDescriptor { uint32_t format_family_id{0}; uint8_t bits_per_sample{0}; bool is_float{false}; bool is_planar{false}; };
}
