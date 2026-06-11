#pragma once

#include "seek_public_envelope.h"
#include "playback_seek_public.h"

namespace kivo::playback::seek_public {

struct SeekPublicRecord {
    SeekPublicEnvelope envelope{};
    PlaybackSeekPublic seek{};
};

} // namespace kivo::playback::seek_public
