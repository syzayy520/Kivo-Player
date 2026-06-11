#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceIntegrityAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
