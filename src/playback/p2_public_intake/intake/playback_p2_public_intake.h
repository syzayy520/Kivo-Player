#pragma once

#include "../identity/p2_public_intake_identity.h"
#include "../anchor/p2_public_intake_anchor_set.h"
#include "../classification/p2_public_intake_classification.h"

namespace kivo::playback::p2_public_intake {

struct PlaybackP2PublicIntake {
    P2PublicIntakeIdentity identity{};
    P2PublicIntakeAnchorSet anchors{};
    P2PublicIntakeClassification classification{};
};

} // namespace kivo::playback::p2_public_intake
