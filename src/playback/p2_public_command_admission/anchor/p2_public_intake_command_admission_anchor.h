#pragma once

#include "playback/p2_public_intake/identity/p2_public_intake_identity.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicIntakeCommandAdmissionAnchor {
    kivo::playback::p2_public_intake::P2PublicIntakeIdentity intake_identity{};
};

} // namespace kivo::playback::p2_public_command_admission
