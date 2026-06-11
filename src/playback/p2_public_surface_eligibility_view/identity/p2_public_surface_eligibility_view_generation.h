#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_eligibility_view {

struct P2PublicSurfaceEligibilityViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceEligibilityViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_eligibility_view
