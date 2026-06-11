#pragma once

#include <cstdint>

namespace kivo::playback::p1_public_surface_closure_audit {

enum class P1PublicSurfaceClosureAuditDropReason : std::uint8_t {
    Superseded,
    LowerPriority,
    Unknown
};

} // namespace kivo::playback::p1_public_surface_closure_audit
