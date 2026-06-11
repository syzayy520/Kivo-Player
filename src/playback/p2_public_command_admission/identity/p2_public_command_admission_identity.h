#pragma once

#include "p2_public_command_admission_id.h"
#include "p2_public_command_admission_sequence_id.h"
#include "p2_public_command_admission_generation.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionIdentity {
    P2PublicCommandAdmissionId admission_id{};
    P2PublicCommandAdmissionSequenceId sequence_id{};
    P2PublicCommandAdmissionGeneration generation{};

    bool operator==(const P2PublicCommandAdmissionIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_command_admission
