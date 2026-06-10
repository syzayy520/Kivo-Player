#pragma once
#include <cstdint>
#include "../../../format/contracts/identity/codec_family.h"
#include "../scope/capability_level.h"
namespace kivo::playback::capability {
struct CodecCapability { kivo::playback::format::CodecFamily family{kivo::playback::format::CodecFamily::Unknown}; CapabilityLevel level{CapabilityLevel::Unknown}; uint32_t max_profile{0}; uint32_t max_level{0}; uint32_t max_resolution_w{0}; uint32_t max_resolution_h{0}; uint32_t max_framerate{0}; };
}
