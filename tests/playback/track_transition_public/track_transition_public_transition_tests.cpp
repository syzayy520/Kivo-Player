#include <cassert>
#include <iostream>

#include "playback/track_transition_public/transition/playback_track_transition_public.h"
#include "playback/track_transition_public/transition/track_transition_public_candidate.h"
#include "playback/track_transition_public/transition/track_transition_public_envelope.h"
#include "playback/track_transition_public/transition/track_transition_public_record.h"

using namespace kivo::playback::track_transition_public;

void test_track_transition_public_transition_default_construction() {
    TrackTransitionPublicCandidate candidate{};
    assert(candidate.identity.transition_id.value == 0);
    assert(candidate.anchors.buffering_anchor.buffering_identity.buffering_id.value == 0);
    assert(candidate.classification.kind == TrackTransitionPublicKind::Unknown);
    PlaybackTrackTransitionPublic transition{};
    assert(transition.identity.transition_id.value == 0);
    TrackTransitionPublicEnvelope envelope{};
    assert(envelope.identity.transition_id.value == 0);
    TrackTransitionPublicRecord record{};
    assert(record.envelope.identity.transition_id.value == 0);
    assert(record.transition.identity.transition_id.value == 0);
    std::cout << "PASS: test_track_transition_public_transition_default_construction" << std::endl;
}
