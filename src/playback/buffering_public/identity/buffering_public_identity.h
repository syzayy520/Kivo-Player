#pragma once

#include "buffering_public_id.h"
#include "buffering_public_sequence_id.h"
#include "buffering_public_generation.h"

namespace kivo::playback::buffering_public {

struct BufferingPublicIdentity {
    BufferingPublicId buffering_id{};
    BufferingPublicSequenceId sequence_id{};
    BufferingPublicGeneration generation{};

    bool operator==(const BufferingPublicIdentity& other) const = default;
};

} // namespace kivo::playback::buffering_public
