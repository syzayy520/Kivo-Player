#pragma once
#include <vector>
#include "codec_capability.h"
namespace kivo::playback::capability {
struct CodecCapabilitySet { std::vector<CodecCapability> entries; };
}
