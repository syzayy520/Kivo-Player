#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceConfirmationAuditId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
