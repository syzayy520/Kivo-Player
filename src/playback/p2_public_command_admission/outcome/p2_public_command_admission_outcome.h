#pragma once

#include "../identity/p2_public_command_admission_identity.h"
#include "p2_public_command_admission_status.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionOutcome {
    P2PublicCommandAdmissionIdentity identity{};
    P2PublicCommandAdmissionStatus status{P2PublicCommandAdmissionStatus::Unknown};

    bool operator==(const P2PublicCommandAdmissionOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_command_admission
