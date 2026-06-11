#pragma once

#include <cstdint>

namespace kivo::playback::public_error_recovery {

enum class PublicErrorRecoveryScope : std::uint8_t {
    PublicSurface,
    EndOfStream,
    Timeline,
    Unknown
};

} // namespace kivo::playback::public_error_recovery
