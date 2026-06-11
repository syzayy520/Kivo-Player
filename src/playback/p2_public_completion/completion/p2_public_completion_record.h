#pragma once

#include "p2_public_completion_envelope.h"
#include "playback_p2_public_completion.h"

namespace kivo::playback::p2_public_completion {

struct P2PublicCompletionRecord {
    P2PublicCompletionEnvelope envelope{};
    PlaybackP2PublicCompletion completion{};
};

} // namespace kivo::playback::p2_public_completion
