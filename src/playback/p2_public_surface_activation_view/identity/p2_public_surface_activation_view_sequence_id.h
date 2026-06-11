#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_surface_activation_view {

struct P2PublicSurfaceActivationViewSequenceId {
    std::uint64_t value{0};

    bool operator==(const P2PublicSurfaceActivationViewSequenceId& other) const = default;
};

} // namespace kivo::playback::p2_public_surface_activation_view
