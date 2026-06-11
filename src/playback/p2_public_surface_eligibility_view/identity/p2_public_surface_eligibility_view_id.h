#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceEligibilityViewId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
