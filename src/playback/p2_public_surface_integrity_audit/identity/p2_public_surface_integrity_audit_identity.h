#pragma once

#include "p2_public_surface_integrity_audit_id.h"
#include "p2_public_surface_integrity_audit_sequence_id.h"
#include "p2_public_surface_integrity_audit_generation.h"

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditIdentity {
    P2PublicSurfaceIntegrityAuditId audit_id{};
    P2PublicSurfaceIntegrityAuditSequenceId sequence_id{};
    P2PublicSurfaceIntegrityAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceIntegrityAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
