#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryGeneration {
    std::uint64_t value{0};

    bool operator==(const PublicErrorRecoveryGeneration& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
