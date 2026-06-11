#pragma once

#include <cstdint>

namespace kivo::playback::p2_public_completion {

enum class P2PublicCompletionRejectionReason : std::uint8_t {
    ReadbackAnchorMissing,
    ClassificationInvalid,
    CompletionIdentityMissing,
    Unknown
};

} // namespace kivo::playback::p2_public_completion
