#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_confirmation_view {

struct P2PublicSurfaceConfirmationViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceConfirmationViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_confirmation_view
