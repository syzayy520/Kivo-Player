#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicSequenceId {
    std::uint64_t value{0};

    bool operator==(const StreamSelectionPublicSequenceId& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
