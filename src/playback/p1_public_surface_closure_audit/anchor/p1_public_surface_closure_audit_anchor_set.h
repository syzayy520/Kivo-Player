#pragma once

#include "public_error_recovery_closure_audit_anchor.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditAnchorSet {
    PublicErrorRecoveryClosureAuditAnchor recovery_anchor{};
};

} // namespace kivo::playback::p1_public_surface_closure_audit
