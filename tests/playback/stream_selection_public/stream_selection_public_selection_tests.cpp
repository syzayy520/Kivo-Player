#include <cassert>
#include <iostream>

#include "playback/stream_selection_public/selection/playback_stream_selection_public.h"
#include "playback/stream_selection_public/selection/stream_selection_public_candidate.h"
#include "playback/stream_selection_public/selection/stream_selection_public_envelope.h"
#include "playback/stream_selection_public/selection/stream_selection_public_record.h"

using namespace kivo::playback::stream_selection_public;

void test_stream_selection_public_selection_default_construction() {
    StreamSelectionPublicCandidate candidate{};
    assert(candidate.identity.selection_id.value == 0);
    assert(candidate.anchors.open_anchor.open_identity.open_id.value == 0);
    assert(candidate.classification.kind == StreamSelectionPublicKind::Unknown);
    StreamSelectionPublicCandidate candidate2{.identity = StreamSelectionPublicIdentity{.selection_id = StreamSelectionPublicId{1}}};
    assert(candidate2.identity.selection_id.value == 1);
    std::cout << "PASS: test_stream_selection_public_candidate_default_construction" << std::endl;
    PlaybackStreamSelectionPublic selection{};
    assert(selection.identity.selection_id.value == 0);
    assert(selection.classification.kind == StreamSelectionPublicKind::Unknown);
    PlaybackStreamSelectionPublic selection2{
        .identity = StreamSelectionPublicIdentity{.selection_id = StreamSelectionPublicId{10}},
        .classification = StreamSelectionPublicClassification{.kind = StreamSelectionPublicKind::Video}
    };
    assert(selection2.identity.selection_id.value == 10);
    assert(selection2.classification.kind == StreamSelectionPublicKind::Video);
    std::cout << "PASS: test_stream_selection_public_default_construction" << std::endl;
    StreamSelectionPublicEnvelope envelope{};
    assert(envelope.identity.selection_id.value == 0);
    StreamSelectionPublicRecord record{};
    assert(record.envelope.identity.selection_id.value == 0);
    assert(record.selection.identity.selection_id.value == 0);
    record.envelope.identity.selection_id = StreamSelectionPublicId{50};
    record.selection.identity.selection_id = StreamSelectionPublicId{60};
    assert(record.envelope.identity.selection_id.value == 50);
    assert(record.selection.identity.selection_id.value == 60);
    std::cout << "PASS: test_stream_selection_public_record_field_modification" << std::endl;
}
