#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/stream_selection_public/outcome/stream_selection_public_outcome.h"
#include "playback/stream_selection_public/outcome/stream_selection_public_rejection_reason.h"
#include "playback/stream_selection_public/outcome/stream_selection_public_drop_reason.h"

using namespace kivo::playback::stream_selection_public;

void test_stream_selection_public_outcome_default_construction() {
    assert(static_cast<std::uint8_t>(StreamSelectionPublicStatus::Recorded) == 0);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicStatus::Rejected) == 1);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicStatus::Dropped) == 2);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicStatus::Unknown) == 3);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicRejectionReason::MediaOpenAnchorMissing) == 0);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicRejectionReason::ClassificationInvalid) == 1);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicRejectionReason::SelectionIdentityMissing) == 2);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicRejectionReason::Unknown) == 3);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicDropReason::Superseded) == 0);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicDropReason::LowerPriority) == 1);
    assert(static_cast<std::uint8_t>(StreamSelectionPublicDropReason::Unknown) == 2);
    StreamSelectionPublicOutcome outcome{};
    assert(outcome.identity.selection_id.value == 0);
    assert(outcome.status == StreamSelectionPublicStatus::Unknown);
    StreamSelectionPublicOutcome outcome2{
        .identity = StreamSelectionPublicIdentity{.selection_id = StreamSelectionPublicId{1}},
        .status = StreamSelectionPublicStatus::Recorded
    };
    assert(outcome2.identity.selection_id.value == 1);
    assert(outcome2.status == StreamSelectionPublicStatus::Recorded);
    assert(outcome == outcome);
    assert(!(outcome == outcome2));
    outcome.identity.selection_id = StreamSelectionPublicId{999};
    outcome.status = StreamSelectionPublicStatus::Rejected;
    assert(outcome.identity.selection_id.value == 999);
    assert(outcome.status == StreamSelectionPublicStatus::Rejected);
    std::cout << "PASS: test_stream_selection_public_outcome_default_construction" << std::endl;
}
