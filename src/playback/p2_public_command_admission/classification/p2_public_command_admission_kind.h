#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

enum class P2PublicCommandAdmissionKind : std::uint8_t {
    PlayIntent,
    PauseIntent,
    NavigationIntent,
    Unknown
};

} // namespace kivo::playback::p2_public_command_admission
