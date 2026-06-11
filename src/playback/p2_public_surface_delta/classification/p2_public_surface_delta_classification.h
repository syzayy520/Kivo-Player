#pragma once

#include "p2_public_surface_delta_kind.h"
#include "p2_public_surface_delta_scope.h"

namespace kivo::playback::p2_public_surface_delta {

struct P2PublicSurfaceDeltaClassification {
    P2PublicSurfaceDeltaKind kind{P2PublicSurfaceDeltaKind::Unknown};
    P2PublicSurfaceDeltaScope scope{P2PublicSurfaceDeltaScope::Unknown};

    bool operator==(const P2PublicSurfaceDeltaClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_delta
