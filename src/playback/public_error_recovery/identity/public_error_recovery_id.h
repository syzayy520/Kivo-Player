#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoveryId {
    std::uint64_t value{0};

    bool operator==(const PublicErrorRecoveryId& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
