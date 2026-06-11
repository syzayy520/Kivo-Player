#pragma once

#include "stream_selection_public_seek_anchor.h"

namespace kivo::playback::seek_public {

struct SeekPublicAnchorSet {
    StreamSelectionPublicSeekAnchor selection_anchor{};
};

} // namespace kivo::playback::seek_public
