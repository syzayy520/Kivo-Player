#include <cassert>
#include <iostream>

#include "playback/stream_selection_public/identity/stream_selection_public_identity.h"
#include "playback/stream_selection_public/anchor/media_open_public_stream_selection_anchor.h"
#include "playback/stream_selection_public/selection/playback_stream_selection_public.h"
#include "playback/stream_selection_public/outcome/stream_selection_public_outcome.h"

using namespace kivo::playback::stream_selection_public;

void test_stream_selection_public_boundary_cross_family() {
    MediaOpenPublicStreamSelectionAnchor anchor{};
    assert(anchor.open_identity.open_id.value == 0);
    assert(anchor.open_identity.sequence_id.value == 0);
    assert(anchor.open_identity.generation.value == 0);
    anchor.open_identity.open_id = kivo::playback::media_open_public::MediaOpenPublicId{123};
    assert(anchor.open_identity.open_id.value == 123);
    PlaybackStreamSelectionPublic selection{
        .identity = StreamSelectionPublicIdentity{
            .selection_id = StreamSelectionPublicId{1},
            .sequence_id = StreamSelectionPublicSequenceId{2},
            .generation = StreamSelectionPublicGeneration{3}
        },
        .anchors = StreamSelectionPublicAnchorSet{
            .open_anchor = MediaOpenPublicStreamSelectionAnchor{
                .open_identity = kivo::playback::media_open_public::MediaOpenPublicIdentity{
                    .open_id = kivo::playback::media_open_public::MediaOpenPublicId{10}
                }
            }
        },
        .classification = StreamSelectionPublicClassification{
            .kind = StreamSelectionPublicKind::Video,
            .scope = StreamSelectionPublicScope::Selection
        }
    };
    assert(selection.identity.selection_id.value == 1);
    assert(selection.identity.sequence_id.value == 2);
    assert(selection.identity.generation.value == 3);
    assert(selection.anchors.open_anchor.open_identity.open_id.value == 10);
    assert(selection.classification.kind == StreamSelectionPublicKind::Video);
    assert(selection.classification.scope == StreamSelectionPublicScope::Selection);
    StreamSelectionPublicOutcome outcome{
        .identity = StreamSelectionPublicIdentity{.selection_id = StreamSelectionPublicId{42}},
        .status = StreamSelectionPublicStatus::Recorded
    };
    assert(outcome.identity.selection_id.value == 42);
    assert(outcome.status == StreamSelectionPublicStatus::Recorded);
    std::cout << "PASS: test_stream_selection_public_boundary_cross_family" << std::endl;
}
