#include <cassert>
#include <iostream>

#include "playback/track_transition_public/identity/track_transition_public_identity.h"
#include "playback/track_transition_public/anchor/buffering_public_track_transition_anchor.h"
#include "playback/track_transition_public/transition/playback_track_transition_public.h"
#include "playback/track_transition_public/outcome/track_transition_public_outcome.h"

using namespace kivo::playback::track_transition_public;

void test_track_transition_public_boundary_cross_family() {
    BufferingPublicTrackTransitionAnchor anchor{};
    anchor.buffering_identity.buffering_id = kivo::playback::buffering_public::BufferingPublicId{123};
    assert(anchor.buffering_identity.buffering_id.value == 123);
    PlaybackTrackTransitionPublic transition{
        .identity = TrackTransitionPublicIdentity{.transition_id = TrackTransitionPublicId{1}},
        .anchors = TrackTransitionPublicAnchorSet{.buffering_anchor = anchor},
        .classification = TrackTransitionPublicClassification{.kind = TrackTransitionPublicKind::Next, .scope = TrackTransitionPublicScope::Timeline}
    };
    assert(transition.identity.transition_id.value == 1);
    assert(transition.anchors.buffering_anchor.buffering_identity.buffering_id.value == 123);
    assert(transition.classification.kind == TrackTransitionPublicKind::Next);
    assert(transition.classification.scope == TrackTransitionPublicScope::Timeline);
    TrackTransitionPublicOutcome outcome{.identity = TrackTransitionPublicIdentity{.transition_id = TrackTransitionPublicId{42}}, .status = TrackTransitionPublicStatus::Recorded};
    assert(outcome.identity.transition_id.value == 42);
    assert(outcome.status == TrackTransitionPublicStatus::Recorded);
    std::cout << "PASS: test_track_transition_public_boundary_cross_family" << std::endl;
}
