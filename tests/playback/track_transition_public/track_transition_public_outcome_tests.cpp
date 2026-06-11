#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/track_transition_public/outcome/track_transition_public_outcome.h"
#include "playback/track_transition_public/outcome/track_transition_public_rejection_reason.h"
#include "playback/track_transition_public/outcome/track_transition_public_drop_reason.h"

using namespace kivo::playback::track_transition_public;

void test_track_transition_public_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(TrackTransitionPublicStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicRejectionReason::BufferingAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicRejectionReason::TransitionIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(TrackTransitionPublicDropReason::Unknown) == 2);
    TrackTransitionPublicOutcome outcome{};
    assert(outcome.identity.transition_id.value == 0);
    assert(outcome.status == TrackTransitionPublicStatus::Unknown);
    std::cout << "PASS: test_track_transition_public_outcome_default_construction" << std::endl;
}
