#pragma once

#include "playback/p2_public_surface_activation_audit/identity/p2_public_surface_activation_audit_identity.h"

namespace kivo::playback::p2_public_surface_commitment_view {

struct P2PublicSurfaceActivationCommitmentViewAnchor {
    kivo::playback::p2_public_surface_activation_audit::P2PublicSurfaceActivationAuditIdentity activation_identity{};
};

} // namespace kivo::playback::p2_public_surface_commitment_view
