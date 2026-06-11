#pragma once

#include "../identity/p2_public_surface_activation_audit_identity.h"
#include "p2_public_surface_activation_audit_status.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationAuditOutcome {
    P2PublicSurfaceActivationAuditIdentity identity{};
    P2PublicSurfaceActivationAuditStatus status{P2PublicSurfaceActivationAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceActivationAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_audit
