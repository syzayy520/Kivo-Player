#pragma once

#include "end_of_stream_public_id.h"
#include "end_of_stream_public_sequence_id.h"
#include "end_of_stream_public_generation.h"

namespace kivo::playback::end_of_stream_public {

struct EndOfStreamPublicIdentity {
    EndOfStreamPublicId end_id{};
    EndOfStreamPublicSequenceId sequence_id{};
    EndOfStreamPublicGeneration generation{};

    bool operator==(const EndOfStreamPublicIdentity& other) const = default;
};

} // namespace kivo::playback::end_of_stream_public
