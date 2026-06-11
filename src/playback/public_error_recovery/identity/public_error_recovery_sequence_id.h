#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

struct PublicErrorRecoverySequenceId {
    std::uint64_t value{0};

    bool operator==(const PublicErrorRecoverySequenceId& other) const = default;
};

} // namespace kivo::playback::public_error_recovery
