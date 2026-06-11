#pragma once

#include "p2_public_surface_activation_audit_kind.h"
#include "p2_public_surface_activation_audit_scope.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationAuditClassification {
    P2PublicSurfaceActivationAuditKind kind{P2PublicSurfaceActivationAuditKind::Unknown};
    P2PublicSurfaceActivationAuditScope scope{P2PublicSurfaceActivationAuditScope::Unknown};

    bool operator==(const P2PublicSurfaceActivationAuditClassification& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_audit
