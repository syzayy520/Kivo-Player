#pragma once

#include "p2_public_surface_final_audit_id.h"
#include "p2_public_surface_final_audit_sequence_id.h"
#include "p2_public_surface_final_audit_generation.h"

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceFinalAuditIdentity {
    P2PublicSurfaceFinalAuditId audit_id{};
    P2PublicSurfaceFinalAuditSequenceId sequence_id{};
    P2PublicSurfaceFinalAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceFinalAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_final_audit
