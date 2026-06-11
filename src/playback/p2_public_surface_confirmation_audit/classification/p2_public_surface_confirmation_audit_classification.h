#pragma once

#include "p2_public_surface_confirmation_audit_kind.h"
#include "p2_public_surface_confirmation_audit_scope.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditClassification {
    P2PublicSurfaceConfirmationAuditKind kind{P2PublicSurfaceConfirmationAuditKind::Unknown};
    P2PublicSurfaceConfirmationAuditScope scope{P2PublicSurfaceConfirmationAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceConfirmationAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
