#pragma once

#include "../identity/p2_public_intake_identity.h"
#include "p2_public_intake_status.h"

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeOutcome {
    P2PublicIntakeIdentity identity{};
    P2PublicIntakeStatus status{P2PublicIntakeStatus::Unknown};

    bool operator==(const P2PublicIntakeOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
