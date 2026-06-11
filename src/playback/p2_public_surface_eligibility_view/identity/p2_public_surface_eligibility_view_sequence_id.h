#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceEligibilityViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
