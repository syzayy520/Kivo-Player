#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

struct BufferingPublicGeneration {
    std::uint64_t value{0};

    bool operator==(const BufferingPublicGeneration& other) const = default;
};

} // namespace kivo::playback::buffering_public
