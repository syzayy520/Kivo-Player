#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

enum class PublicErrorRecoveryKind : std::uint8_t {
    EndReached,
    Recoverable,
    Terminal,
    Unknown
};

} // namespace kivo::playback::public_error_recovery
