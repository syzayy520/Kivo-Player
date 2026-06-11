#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

struct P1PublicSurfaceClosureAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P1PublicSurfaceClosureAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p1_public_surface_closure_audit
