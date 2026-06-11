#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewGeneration {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceConfirmationViewGeneration& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
