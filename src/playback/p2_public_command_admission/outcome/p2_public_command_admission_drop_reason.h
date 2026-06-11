#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

enum class P2PublicCommandAdmissionDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p2_public_command_admission
