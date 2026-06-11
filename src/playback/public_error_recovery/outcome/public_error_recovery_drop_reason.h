#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

enum class PublicErrorRecoveryDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::public_error_recovery
