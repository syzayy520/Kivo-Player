#pragma once

#include "p2_public_command_admission_envelope.h"
#include "playback_p2_public_command_admission.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionRecord {
    P2PublicCommandAdmissionEnvelope envelope{};
    PlaybackP2PublicCommandAdmission admission{};
};

} // namespace kivo::playback::p2_public_command_admission
