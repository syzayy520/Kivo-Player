#pragma once

#include "p2_public_command_admission_kind.h"
#include "p2_public_command_admission_scope.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionClassification {
    P2PublicCommandAdmissionKind kind{P2PublicCommandAdmissionKind::Unknown};
    P2PublicCommandAdmissionScope scope{P2PublicCommandAdmissionScope::Unknown};

    bool operator==(const P2PublicCommandAdmissionClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_command_admission
