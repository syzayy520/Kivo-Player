#pragma once

#include "playback/p2_public_surface_confirmation_audit/identity/p2_public_surface_confirmation_audit_identity.h"

namespace kivo::playback::p2_public_surface_validation_view {

struct P2PublicSurfaceConfirmationValidationViewAnchor {
    kivo::playback::p2_public_surface_confirmation_audit::P2PublicSurfaceConfirmationAuditIdentity confirmation_identity{};
};

} // namespace kivo::playback::p2_public_surface_validation_view
