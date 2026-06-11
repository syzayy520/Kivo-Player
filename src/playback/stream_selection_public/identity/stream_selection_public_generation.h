#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const StreamSelectionPublicGeneration& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
