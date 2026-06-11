#pragma once

#include "end_of_stream_public_envelope.h"
#include "playback_end_of_stream_public.h"

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicRecord {
    EndOfStreamPublicEnvelope envelope{};
    PlaybackEndOfStreamPublic end{};
};

} // namespace kivo::playback::end_of_stream_public
