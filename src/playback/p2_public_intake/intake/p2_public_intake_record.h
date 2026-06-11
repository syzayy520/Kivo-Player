#pragma once

#include "p2_public_intake_envelope.h"
#include "playback_p2_public_intake.h"

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeRecord {
    P2PublicIntakeEnvelope envelope{};
    PlaybackP2PublicIntake intake{};
};

} // namespace kivo::playback::p2_public_intake
