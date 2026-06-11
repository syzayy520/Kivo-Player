#pragma once

#include "p1_public_surface_closure_audit_id.h"
#include "p1_public_surface_closure_audit_sequence_id.h"
#include "p1_public_surface_closure_audit_generation.h"

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditIdentity {
    P1PublicSurfaceClosureAuditId audit_id{};
    P1PublicSurfaceClosureAuditSequenceId sequence_id{};
    P1PublicSurfaceClosureAuditGeneration generation{};

    bool operator==(const P1PublicSurfaceClosureAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p1_public_surface_closure_audit
