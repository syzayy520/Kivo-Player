#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_audit {

struct P2PublicSurfaceActivationAuditGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceActivationAuditGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_audit
