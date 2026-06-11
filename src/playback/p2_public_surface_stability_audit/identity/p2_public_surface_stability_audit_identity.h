#pragma once

#include "p2_public_surface_stability_audit_id.h"
#include "p2_public_surface_stability_audit_sequence_id.h"
#include "p2_public_surface_stability_audit_generation.h"

namespace kivo::playback::p2_public_surface_stability_audit {

struct P2PublicSurfaceStabilityAuditIdentity {
    P2PublicSurfaceStabilityAuditId audit_id{};
    P2PublicSurfaceStabilityAuditSequenceId sequence_id{};
    P2PublicSurfaceStabilityAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceStabilityAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_stability_audit
