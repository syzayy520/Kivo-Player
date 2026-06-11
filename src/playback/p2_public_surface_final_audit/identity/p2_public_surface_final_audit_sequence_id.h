#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_final_audit {

struct P2PublicSurfaceFinalAuditSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceFinalAuditSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_final_audit
