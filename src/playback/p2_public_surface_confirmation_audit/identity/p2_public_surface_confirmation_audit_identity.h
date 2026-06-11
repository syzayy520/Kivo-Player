#pragma once

#include "p2_public_surface_confirmation_audit_id.h"
#include "p2_public_surface_confirmation_audit_sequence_id.h"
#include "p2_public_surface_confirmation_audit_generation.h"

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditIdentity {
    P2PublicSurfaceConfirmationAuditId audit_id{};
    P2PublicSurfaceConfirmationAuditSequenceId sequence_id{};
    P2PublicSurfaceConfirmationAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceConfirmationAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
