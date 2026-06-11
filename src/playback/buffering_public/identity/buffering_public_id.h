#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

struct BufferingPublicId {
    std::uint64_t value{0};

    bool operator==(const BufferingPublicId& other) const = default;
};

} // namespace kivo::playback::buffering_public
