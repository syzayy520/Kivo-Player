#pragma once
#include <cstdint>
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct SampleFormatCapability { uint32_t format_family_id{0}; CapabilityLevel level{CapabilityLevel::Unknown}; };
}
