#include <cassert>
#include <iostream>

#include "playback/media_open_public/anchor/playback_session_public_media_open_anchor.h"
#include "playback/media_open_public/anchor/media_open_public_anchor_set.h"

using namespace kivo::playback::media_open_public;
using namespace kivo::playback::session_public;

void test_media_open_public_anchor_default_construction() {
    PlaybackSessionPublicMediaOpenAnchor anchor{};
    assert(anchor.session_identity.session_id.value == 0);
    assert(anchor.session_identity.sequence_id.value == 0);
    assert(anchor.session_identity.generation.value == 0);

    PlaybackSessionPublicMediaOpenAnchor anchor2{
        .session_identity = PlaybackSessionPublicIdentity{
            .session_id = PlaybackSessionPublicId{5},
            .sequence_id = PlaybackSessionPublicSequenceId{10},
            .generation = PlaybackSessionPublicGeneration{15}
        }
    };
    assert(anchor2.session_identity.session_id.value == 5);
    assert(anchor2.session_identity.sequence_id.value == 10);
    assert(anchor2.session_identity.generation.value == 15);

    std::cout << "PASS: test_media_open_public_anchor_default_construction" << std::endl;

    MediaOpenPublicAnchorSet anchor_set{};
    assert(anchor_set.session_anchor.session_identity.session_id.value == 0);

    std::cout << "PASS: test_media_open_public_anchor_set_default_construction" << std::endl;
}
