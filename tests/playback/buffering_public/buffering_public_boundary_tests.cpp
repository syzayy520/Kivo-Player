#include <cassert>
#include <iostream>

#include "playback/buffering_public/identity/buffering_public_identity.h"
#include "playback/buffering_public/anchor/seek_public_buffering_anchor.h"
#include "playback/buffering_public/buffering/playback_buffering_public.h"
#include "playback/buffering_public/outcome/buffering_public_outcome.h"

using namespace kivo::playback::buffering_public;

void test_buffering_public_boundary_cross_family() {
    SeekPublicBufferingAnchor anchor{};
    anchor.seek_identity.seek_id = kivo::playback::seek_public::SeekPublicId{123};
    assert(anchor.seek_identity.seek_id.value == 123);
    PlaybackBufferingPublic buffering{
        .identity = BufferingPublicIdentity{.buffering_id = BufferingPublicId{1}},
        .anchors = BufferingPublicAnchorSet{.seek_anchor = anchor},
        .classification = BufferingPublicClassification{.kind = BufferingPublicKind::Priming, .scope = BufferingPublicScope::Timeline}
    };
    assert(buffering.identity.buffering_id.value == 1);
    assert(buffering.anchors.seek_anchor.seek_identity.seek_id.value == 123);
    assert(buffering.classification.kind == BufferingPublicKind::Priming);
    assert(buffering.classification.scope == BufferingPublicScope::Timeline);
    BufferingPublicOutcome outcome{.identity = BufferingPublicIdentity{.buffering_id = BufferingPublicId{42}}, .status = BufferingPublicStatus::Recorded};
    assert(outcome.identity.buffering_id.value == 42);
    assert(outcome.status == BufferingPublicStatus::Recorded);
    std::cout << "PASS: test_buffering_public_boundary_cross_family" << std::endl;
}
