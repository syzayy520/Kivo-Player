#pragma once

#include "playback_session_public_id.h"
#include "playback_session_public_sequence_id.h"
#include "playback_session_public_generation.h"

namespace kivo::playback::session_public {

struct PlaybackSessionPublicIdentity {
    PlaybackSessionPublicId session_id{};
    PlaybackSessionPublicSequenceId sequence_id{};
    PlaybackSessionPublicGeneration generation{};

    bool operator==(const PlaybackSessionPublicIdentity& other) const = default;
};

} // namespace kivo::playback::session_public
