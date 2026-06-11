#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_retention_audit {

struct P2PublicSurfaceRetentionAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceRetentionAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_retention_audit
