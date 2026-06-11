#pragma once

#include "seek_public_id.h"
#include "seek_public_sequence_id.h"
#include "seek_public_generation.h"

namespace kivo::playback::seek_public {

struct SeekPublicIdentity {
    SeekPublicId seek_id{};
    SeekPublicSequenceId sequence_id{};
    SeekPublicGeneration generation{};

    bool operator==(const SeekPublicIdentity& other) const = default;
};

} // namespace kivo::playback::seek_public
