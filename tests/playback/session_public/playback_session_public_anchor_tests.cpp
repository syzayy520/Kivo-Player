#include <cassert>
#include <iostream>

#include "playback/session_public/anchor/playback_lifecycle_phase_session_public_anchor.h"
#include "playback/session_public/anchor/playback_session_public_anchor_set.h"

using namespace kivo::playback::session_public;
using namespace kivo::playback::lifecycle_phase;

void test_session_public_anchor_default_construction() {
    PlaybackLifecyclePhaseSessionPublicAnchor anchor{};
    assert(anchor.phase_identity.phase_id.value == 0);
    assert(anchor.phase_identity.sequence_id.value == 0);
    assert(anchor.phase_identity.generation.value == 0);

    PlaybackLifecyclePhaseSessionPublicAnchor anchor2{
        .phase_identity = PlaybackLifecyclePhaseIdentity{
            .phase_id = PlaybackLifecyclePhaseId{5},
            .sequence_id = PlaybackLifecyclePhaseSequenceId{10},
            .generation = PlaybackLifecyclePhaseGeneration{15}
        }
    };
    assert(anchor2.phase_identity.phase_id.value == 5);
    assert(anchor2.phase_identity.sequence_id.value == 10);
    assert(anchor2.phase_identity.generation.value == 15);

    std::cout << "PASS: test_session_public_anchor_default_construction" << std::endl;

    PlaybackSessionPublicAnchorSet anchor_set{};
    assert(anchor_set.phase_anchor.phase_identity.phase_id.value == 0);

    std::cout << "PASS: test_session_public_anchor_set_default_construction" << std::endl;
}
