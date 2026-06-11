#pragma once

#include "seek_public_buffering_anchor.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicAnchorSet {
    SeekPublicBufferingAnchor seek_anchor{};
};

} // namespace kivo::playback::buffering_public
