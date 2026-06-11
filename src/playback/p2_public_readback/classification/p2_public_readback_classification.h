#pragma once

#include "p2_public_readback_kind.h"
#include "p2_public_readback_scope.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackClassification {
    P2PublicReadbackKind kind{P2PublicReadbackKind::Unknown};
    P2PublicReadbackScope scope{P2PublicReadbackScope::Unknown};

    bool operator==(const P2PublicReadbackClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_readback
