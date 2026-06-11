#pragma once

#include "playback/p1_public_surface_closure_audit/identity/p1_public_surface_closure_audit_identity.h"

namespace kivo::playback::p2_public_intake {

struct P1ClosureIntakeAnchor {
    kivo::playback::p1_public_surface_closure_audit::P1PublicSurfaceClosureAuditIdentity closure_identity{};
};

} // namespace kivo::playback::p2_public_intake
