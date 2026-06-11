#include <cassert>
#include <iostream>

#include "playback/end_of_stream_public/identity/end_of_stream_public_identity.h"
#include "playback/end_of_stream_public/anchor/track_transition_public_end_of_stream_anchor.h"
#include "playback/end_of_stream_public/end/playback_end_of_stream_public.h"
#include "playback/end_of_stream_public/outcome/end_of_stream_public_outcome.h"

using namespace kivo::playback::end_of_stream_public;

void test_end_of_stream_public_boundary_cross_family() {
    TrackTransitionPublicEndOfStreamAnchor anchor{};
    anchor.transition_identity.transition_id = kivo::playback::track_transition_public::TrackTransitionPublicId{123};
    assert(anchor.transition_identity.transition_id.value == 123);
    PlaybackEndOfStreamPublic end{
        .identity = EndOfStreamPublicIdentity{.end_id = EndOfStreamPublicId{1}},
        .anchors = EndOfStreamPublicAnchorSet{.transition_anchor = anchor},
        .classification = EndOfStreamPublicClassification{.kind = EndOfStreamPublicKind::Natural, .scope = EndOfStreamPublicScope::Timeline}
    };
    assert(end.identity.end_id.value == 1);
    assert(end.anchors.transition_anchor.transition_identity.transition_id.value == 123);
    assert(end.classification.kind == EndOfStreamPublicKind::Natural);
    assert(end.classification.scope == EndOfStreamPublicScope::Timeline);
    EndOfStreamPublicOutcome outcome{.identity = EndOfStreamPublicIdentity{.end_id = EndOfStreamPublicId{42}}, .status = EndOfStreamPublicStatus::Recorded};
    assert(outcome.identity.end_id.value == 42);
    assert(outcome.status == EndOfStreamPublicStatus::Recorded);
    std::cout << "PASS: test_end_of_stream_public_boundary_cross_family" << std::endl;
}
