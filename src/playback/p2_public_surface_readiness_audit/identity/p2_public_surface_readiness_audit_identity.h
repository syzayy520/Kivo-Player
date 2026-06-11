#pragma once

#include "p2_public_surface_readiness_audit_id.h"
#include "p2_public_surface_readiness_audit_sequence_id.h"
#include "p2_public_surface_readiness_audit_generation.h"

namespace kivo::playback::p2_public_surface_readiness_audit {

struct P2PublicSurfaceReadinessAuditIdentity {
    P2PublicSurfaceReadinessAuditId audit_id{};
    P2PublicSurfaceReadinessAuditSequenceId sequence_id{};
    P2PublicSurfaceReadinessAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceReadinessAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_readiness_audit
