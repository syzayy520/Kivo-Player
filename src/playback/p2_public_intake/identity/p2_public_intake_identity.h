#pragma once

#include "p2_public_intake_id.h"
#include "p2_public_intake_sequence_id.h"
#include "p2_public_intake_generation.h"

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeIdentity {
    P2PublicIntakeId intake_id{};
    P2PublicIntakeSequenceId sequence_id{};
    P2PublicIntakeGeneration generation{};

    bool operator==(const P2PublicIntakeIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
