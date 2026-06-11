#pragma once

#include <cstdint>

namespace kivo::playback::buffering_public {

struct BufferingPublicSequenceId {
    std::uint64_t value{0};

    bool operator==(const BufferingPublicSequenceId& other) const = default;
};

} // namespace kivo::playback::buffering_public
