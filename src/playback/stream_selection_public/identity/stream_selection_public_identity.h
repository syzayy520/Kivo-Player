#pragma once

#include "stream_selection_public_id.h"
#include "stream_selection_public_sequence_id.h"
#include "stream_selection_public_generation.h"

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicIdentity {
    StreamSelectionPublicId selection_id{};
    StreamSelectionPublicSequenceId sequence_id{};
    StreamSelectionPublicGeneration generation{};

    bool operator==(const StreamSelectionPublicIdentity& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
