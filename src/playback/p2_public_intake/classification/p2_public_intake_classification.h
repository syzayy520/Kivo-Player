#pragma once

#include "p2_public_intake_kind.h"
#include "p2_public_intake_scope.h"

namespace kivo::playback::p2_public_intake {

struct P2PublicIntakeClassification {
    P2PublicIntakeKind kind{P2PublicIntakeKind::Unknown};
    P2PublicIntakeScope scope{P2PublicIntakeScope::Unknown};

    bool operator==(const P2PublicIntakeClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_intake
