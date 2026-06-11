#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

enum class P2PublicCommandAdmissionStatus : std::uint8_t {
    Admitted,
    Rejected,
    Deferred,
    Unknown
};

} // namespace kivo::playback::p2_public_command_admission
