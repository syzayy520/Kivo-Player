#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/lifecycle_phase/outcome/playback_lifecycle_phase_outcome.h"
#include "playback/lifecycle_phase/outcome/playback_lifecycle_phase_rejection_reason.h"
#include "playback/lifecycle_phase/outcome/playback_lifecycle_phase_drop_reason.h"

using namespace kivo::playback::lifecycle_phase;

void test_lifecycle_phase_outcome_default_construction() {
    {
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseStatus::Recorded) == 0);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseStatus::Rejected) == 1);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseStatus::Dropped) == 2);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseStatus::Unknown) == 3);
        std::cout << "PASS: test_lifecycle_phase_status_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseRejectionReason::BoundaryAnchorMissing) == 0);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseRejectionReason::ClassificationInvalid) == 1);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseRejectionReason::PhaseIdentityMissing) == 2);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseRejectionReason::Unknown) == 3);
        std::cout << "PASS: test_lifecycle_phase_rejection_reason_enum_values" << std::endl;
    }

    {
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseDropReason::Superseded) == 0);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseDropReason::LowerPriority) == 1);
        assert(static_cast<std::uint8_t>(PlaybackLifecyclePhaseDropReason::Unknown) == 2);
        std::cout << "PASS: test_lifecycle_phase_drop_reason_enum_values" << std::endl;
    }

    PlaybackLifecyclePhaseOutcome outcome{};
    assert(outcome.identity.phase_id.value == 0);
    assert(outcome.status == PlaybackLifecyclePhaseStatus::Unknown);

    PlaybackLifecyclePhaseOutcome outcome2{
        .identity = PlaybackLifecyclePhaseIdentity{
            .phase_id = PlaybackLifecyclePhaseId{1}
        },
        .status = PlaybackLifecyclePhaseStatus::Recorded
    };
    assert(outcome2.identity.phase_id.value == 1);
    assert(outcome2.status == PlaybackLifecyclePhaseStatus::Recorded);

    assert(outcome == outcome);
    assert(!(outcome == outcome2));

    std::cout << "PASS: test_lifecycle_phase_outcome_default_construction" << std::endl;

    outcome.identity.phase_id = PlaybackLifecyclePhaseId{999};
    outcome.status = PlaybackLifecyclePhaseStatus::Rejected;

    assert(outcome.identity.phase_id.value == 999);
    assert(outcome.status == PlaybackLifecyclePhaseStatus::Rejected);

    std::cout << "PASS: test_lifecycle_phase_outcome_field_modification" << std::endl;
}
