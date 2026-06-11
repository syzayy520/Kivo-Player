#pragma once

#include "stream_selection_public_envelope.h"
#include "playback_stream_selection_public.h"

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicRecord {
    StreamSelectionPublicEnvelope envelope{};
    PlaybackStreamSelectionPublic selection{};
};

} // namespace kivo::playback::stream_selection_public
