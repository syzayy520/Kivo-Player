// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::format {
struct ChannelLayoutDescriptor { uint64_t channel_mask{0}; uint8_t channel_count{0}; };
}
