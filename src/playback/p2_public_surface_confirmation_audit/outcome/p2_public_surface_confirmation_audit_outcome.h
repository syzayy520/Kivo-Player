#pragma once

#include "../identity/p2_public_surface_confirmation_audit_identity.h"
#include "p2_public_surface_confirmation_audit_status.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditOutcome {
    P2PublicSurfaceConfirmationAuditIdentity identity{};
    P2PublicSurfaceConfirmationAuditStatus status{P2PublicSurfaceConfirmationAuditStatus::Unknown};

    bool operator==(const P2PublicSurfaceConfirmationAuditOutcome& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
