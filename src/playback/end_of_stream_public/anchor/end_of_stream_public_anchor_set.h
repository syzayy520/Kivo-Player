#pragma once

#include "track_transition_public_end_of_stream_anchor.h"

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicAnchorSet {
    TrackTransitionPublicEndOfStreamAnchor transition_anchor{};
};

} // namespace kivo::playback::end_of_stream_public
