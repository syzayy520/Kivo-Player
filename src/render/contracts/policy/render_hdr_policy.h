#pragma once
#include "format/contracts/hdr/hdr_static_metadata.h"
namespace kivo::playback::render {
enum class RenderHdrIntent {
    PassthroughHdr,
    ToneMapToReference,
    ToneMapToTarget,
    Unknown
};

struct RenderHdrPolicy {
    RenderHdrIntent intent{RenderHdrIntent::Unknown};
    kivo::playback::format::HdrStaticMetadata hdr_metadata{};
};
}
