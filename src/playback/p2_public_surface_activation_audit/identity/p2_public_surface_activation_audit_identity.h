#pragma once

#include "p2_public_surface_activation_audit_id.h"
#include "p2_public_surface_activation_audit_sequence_id.h"
#include "p2_public_surface_activation_audit_generation.h"

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationAuditIdentity {
    P2PublicSurfaceActivationAuditId audit_id{};
    P2PublicSurfaceActivationAuditSequenceId sequence_id{};
    P2PublicSurfaceActivationAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceActivationAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_audit
