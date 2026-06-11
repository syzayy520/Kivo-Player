#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_integrity_audit {

struct P2PublicSurfaceIntegrityAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceIntegrityAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_integrity_audit
