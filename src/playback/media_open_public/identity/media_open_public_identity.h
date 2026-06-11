#pragma once

#include "media_open_public_id.h"
#include "media_open_public_sequence_id.h"
#include "media_open_public_generation.h"

namespace kivo::playback::media_open_public {

struct MediaOpenPublicIdentity {
    MediaOpenPublicId open_id{};
    MediaOpenPublicSequenceId sequence_id{};
    MediaOpenPublicGeneration generation{};

    bool operator==(const MediaOpenPublicIdentity& other) const = default;
};

} // namespace kivo::playback::media_open_public
