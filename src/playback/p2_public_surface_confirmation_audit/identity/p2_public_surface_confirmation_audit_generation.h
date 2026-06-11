#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_audit {

struct P2PublicSurfaceConfirmationAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceConfirmationAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_audit
