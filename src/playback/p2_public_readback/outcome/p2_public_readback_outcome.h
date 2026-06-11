#pragma once

#include "../identity/p2_public_readback_identity.h"
#include "p2_public_readback_status.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackOutcome {
    P2PublicReadbackIdentity identity{};
    P2PublicReadbackStatus status{P2PublicReadbackStatus::Unknown};

    bool operator==(const P2PublicReadbackOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_readback
