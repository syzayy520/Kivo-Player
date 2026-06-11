#include <cassert>
#include <iostream>

#include "playback/stream_selection_public/anchor/media_open_public_stream_selection_anchor.h"
#include "playback/stream_selection_public/anchor/stream_selection_public_anchor_set.h"

using namespace kivo::playback::stream_selection_public;
using namespace kivo::playback::media_open_public;

void test_stream_selection_public_anchor_default_construction() {
    MediaOpenPublicStreamSelectionAnchor anchor{};
    assert(anchor.open_identity.open_id.value == 0);
    assert(anchor.open_identity.sequence_id.value == 0);
    assert(anchor.open_identity.generation.value == 0);
    MediaOpenPublicStreamSelectionAnchor anchor2{
        .open_identity = MediaOpenPublicIdentity{
            .open_id = MediaOpenPublicId{5},
            .sequence_id = MediaOpenPublicSequenceId{10},
            .generation = MediaOpenPublicGeneration{15}
        }
    };
    assert(anchor2.open_identity.open_id.value == 5);
    assert(anchor2.open_identity.sequence_id.value == 10);
    assert(anchor2.open_identity.generation.value == 15);
    std::cout << "PASS: test_stream_selection_public_anchor_default_construction" << std::endl;
    StreamSelectionPublicAnchorSet anchor_set{};
    assert(anchor_set.open_anchor.open_identity.open_id.value == 0);
    std::cout << "PASS: test_stream_selection_public_anchor_set_default_construction" << std::endl;
}
