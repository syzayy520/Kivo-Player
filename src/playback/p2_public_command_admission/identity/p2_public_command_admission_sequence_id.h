#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicCommandAdmissionSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_command_admission
