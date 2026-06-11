#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_consistency_audit {

struct P2PublicSurfaceConsistencyAuditSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceConsistencyAuditSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_consistency_audit
