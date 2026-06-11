#pragma once

#include "playback/public_error_recovery/identity/public_error_recovery_identity.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct PublicErrorRecoveryClosureAuditAnchor {
    kivo::playback::public_error_recovery::PublicErrorRecoveryIdentity recovery_identity{};
};

} // namespace kivo::playback::p1_public_surface_closure_audit
