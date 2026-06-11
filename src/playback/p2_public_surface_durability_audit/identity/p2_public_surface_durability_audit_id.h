#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_durability_audit {

struct P2PublicSurfaceDurabilityAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceDurabilityAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_durability_audit
