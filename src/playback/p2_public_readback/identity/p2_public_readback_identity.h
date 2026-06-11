#pragma once

#include "p2_public_readback_id.h"
#include "p2_public_readback_sequence_id.h"
#include "p2_public_readback_generation.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackIdentity {
    P2PublicReadbackId readback_id{};
    P2PublicReadbackSequenceId sequence_id{};
    P2PublicReadbackGeneration generation{};

    bool operator==(const P2PublicReadbackIdentity& other) const = default;
};

} // namespace kivo::playback::p2_public_readback
