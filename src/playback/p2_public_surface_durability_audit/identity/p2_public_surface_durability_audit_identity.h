#pragma once

#include "p2_public_surface_durability_audit_id.h"
#include "p2_public_surface_durability_audit_sequence_id.h"
#include "p2_public_surface_durability_audit_generation.h"

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityAuditIdentity {
    P2PublicSurfaceDurabilityAuditId audit_id{};
    P2PublicSurfaceDurabilityAuditSequenceId sequence_id{};
    P2PublicSurfaceDurabilityAuditGeneration generation{};

    bool operator==(const P2PublicSurfaceDurabilityAuditIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_audit
