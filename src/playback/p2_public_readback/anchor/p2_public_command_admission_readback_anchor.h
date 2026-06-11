#pragma once

#include "playback/p2_public_command_admission/identity/p2_public_command_admission_identity.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicCommandAdmissionReadbackAnchor {
    kivo::playback::p2_public_command_admission::P2PublicCommandAdmissionIdentity admission_identity{};
};

} // namespace kivo::playback::p2_public_readback
