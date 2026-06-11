#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

enum class P2PublicCommandAdmissionScope : std::uint8_t {
    PublicSurface,
    IntakeBoundary,
    CommandBoundary,
    Unknown
};

} // namespace kivo::playback::p2_public_command_admission
