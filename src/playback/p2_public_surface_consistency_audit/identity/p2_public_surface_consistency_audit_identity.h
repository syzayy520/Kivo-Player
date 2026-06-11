#pragma once

#include "p2_public_surface_consistency_audit_id.h"
#include "p2_public_surface_consistency_audit_sequence_id.h"
#include "p2_public_surface_consistency_audit_generation.h"

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditIdentity {
    P2PublicSurfaceConsistencyAuditId audit_id{};
    P2PublicSurfaceConsistencyAuditSequenceId sequence_id{};
    P2PublicSurfaceConsistencyAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceConsistencyAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
