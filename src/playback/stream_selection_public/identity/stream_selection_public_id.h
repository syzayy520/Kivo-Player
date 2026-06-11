#pragma once

#include <cstdint>

namespace kivo::playback::stream_selection_public {

struct StreamSelectionPublicId {
    std::uint64_t value{0};

    bool operator==(const StreamSelectionPublicId& other) const = default;
};

} // namespace kivo::playback::stream_selection_public
