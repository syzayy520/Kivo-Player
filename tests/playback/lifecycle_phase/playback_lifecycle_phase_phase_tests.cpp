#include <cassert>
#include <iostream>

#include "playback/lifecycle_phase/phase/playback_lifecycle_phase.h"
#include "playback/lifecycle_phase/phase/playback_lifecycle_phase_candidate.h"
#include "playback/lifecycle_phase/phase/playback_lifecycle_phase_envelope.h"
#include "playback/lifecycle_phase/phase/playback_lifecycle_phase_record.h"

using namespace kivo::playback::lifecycle_phase;

void test_lifecycle_phase_phase_default_construction() {
    PlaybackLifecyclePhaseCandidate candidate{};
    assert(candidate.identity.phase_id.value == 0);
    assert(candidate.anchors.boundary_anchor.boundary_identity.boundary_id.value == 0);
    assert(candidate.classification.kind == PlaybackLifecyclePhaseKind::Unknown);

    PlaybackLifecyclePhaseCandidate candidate2{
        .identity = PlaybackLifecyclePhaseIdentity{
            .phase_id = PlaybackLifecyclePhaseId{1}
        }
    };
    assert(candidate2.identity.phase_id.value == 1);

    std::cout << "PASS: test_lifecycle_phase_candidate_default_construction" << std::endl;

    PlaybackLifecyclePhase phase{};
    assert(phase.identity.phase_id.value == 0);
    assert(phase.classification.kind == PlaybackLifecyclePhaseKind::Unknown);

    PlaybackLifecyclePhase phase2{
        .identity = PlaybackLifecyclePhaseIdentity{
            .phase_id = PlaybackLifecyclePhaseId{10}
        },
        .classification = PlaybackLifecyclePhaseClassification{
            .kind = PlaybackLifecyclePhaseKind::Created
        }
    };
    assert(phase2.identity.phase_id.value == 10);
    assert(phase2.classification.kind == PlaybackLifecyclePhaseKind::Created);

    std::cout << "PASS: test_lifecycle_phase_default_construction" << std::endl;

    PlaybackLifecyclePhaseEnvelope envelope{};
    assert(envelope.identity.phase_id.value == 0);

    PlaybackLifecyclePhaseEnvelope envelope2{
        .identity = PlaybackLifecyclePhaseIdentity{
            .phase_id = PlaybackLifecyclePhaseId{20}
        }
    };
    assert(envelope2.identity.phase_id.value == 20);

    std::cout << "PASS: test_lifecycle_phase_envelope_default_construction" << std::endl;

    PlaybackLifecyclePhaseRecord record{};
    assert(record.envelope.identity.phase_id.value == 0);
    assert(record.phase.identity.phase_id.value == 0);

    PlaybackLifecyclePhaseRecord record2{
        .envelope = PlaybackLifecyclePhaseEnvelope{
            .identity = PlaybackLifecyclePhaseIdentity{
                .phase_id = PlaybackLifecyclePhaseId{30}
            }
        },
        .phase = PlaybackLifecyclePhase{
            .identity = PlaybackLifecyclePhaseIdentity{
                .phase_id = PlaybackLifecyclePhaseId{40}
            }
        }
    };
    assert(record2.envelope.identity.phase_id.value == 30);
    assert(record2.phase.identity.phase_id.value == 40);

    std::cout << "PASS: test_lifecycle_phase_record_default_construction" << std::endl;

    record.envelope.identity.phase_id = PlaybackLifecyclePhaseId{50};
    record.phase.identity.phase_id = PlaybackLifecyclePhaseId{60};

    assert(record.envelope.identity.phase_id.value == 50);
    assert(record.phase.identity.phase_id.value == 60);

    std::cout << "PASS: test_lifecycle_phase_record_field_modification" << std::endl;
}
