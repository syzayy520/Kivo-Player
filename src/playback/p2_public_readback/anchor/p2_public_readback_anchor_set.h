#pragma once

#include "p2_public_command_admission_readback_anchor.h"

namespace kivo::playback::p2_public_readback {

struct P2PublicReadbackAnchorSet {
    P2PublicCommandAdmissionReadbackAnchor admission_anchor{};
};

} // namespace kivo::playback::p2_public_readback
