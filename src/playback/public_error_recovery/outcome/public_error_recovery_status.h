#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

enum class PublicErrorRecoveryStatus : std::uint8_t {
    Recorded,
    Rejected,
    Dropped,
    Unknown
};

} // namespace kivo::playback::public_error_recovery
