#pragma once

#include "../identity/p2_public_command_admission_identity.h"
#include "../anchor/p2_public_command_admission_anchor_set.h"
#include "../classification/p2_public_command_admission_classification.h"

namespace kivo::playback::p2_public_command_admission {

struct P2PublicCommandAdmissionEnvelope {
    P2PublicCommandAdmissionIdentity identity{};
    P2PublicCommandAdmissionAnchorSet anchors{};
    P2PublicCommandAdmissionClassification classification{};
};

} // namespace kivo::playback::p2_public_command_admission
