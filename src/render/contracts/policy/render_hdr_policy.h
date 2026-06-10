#pragma once
#include "format/contracts/hdr/hdr_static_metadata.h"
namespace kivo::playback::render {
enum class HdrMode {
    Off,
    Auto,
    ForceSDR,
    ForceHDR
};
struct RenderHdrPolicy {
    HdrMode mode{HdrMode::Off};
    kivo::playback::format::HdrStaticMetadata hdr_metadata{};
};
}
