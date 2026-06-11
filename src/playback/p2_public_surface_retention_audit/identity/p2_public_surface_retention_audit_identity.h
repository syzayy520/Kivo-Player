#pragma once

#include "p2_public_surface_retention_audit_id.h"
#include "p2_public_surface_retention_audit_sequence_id.h"
#include "p2_public_surface_retention_audit_generation.h"

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditIdentity {
    P2PublicSurfaceRetentionAuditId audit_id{};
    P2PublicSurfaceRetentionAuditSequenceId sequence_id{};
    P2PublicSurfaceRetentionAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceRetentionAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_audit
