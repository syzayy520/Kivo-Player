// Copyright (c) 2026 Kivo Project. All rights reserved.
#pragma once
#include <cstdint>
namespace kivo::playback::format {
enum class HdrDynamicMetadataType { None, ST2094_10, ST2094_40 };
struct HdrDynamicMetadataEnvelope { HdrDynamicMetadataType type{HdrDynamicMetadataType::None}; uint8_t version{0}; bool present{false}; };
}
