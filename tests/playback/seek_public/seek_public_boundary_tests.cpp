#include <cassert>
#include <iostream>

#include "playback/seek_public/identity/seek_public_identity.h"
#include "playback/seek_public/anchor/stream_selection_public_seek_anchor.h"
#include "playback/seek_public/seek/playback_seek_public.h"
#include "playback/seek_public/outcome/seek_public_outcome.h"

using namespace kivo::playback::seek_public;

void test_seek_public_boundary_cross_family() {
    StreamSelectionPublicSeekAnchor anchor{};
    anchor.selection_identity.selection_id = kivo::playback::stream_selection_public::StreamSelectionPublicId{123};
    assert(anchor.selection_identity.selection_id.value == 123);
    PlaybackSeekPublic seek{
        .identity = SeekPublicIdentity{.seek_id = SeekPublicId{1}},
        .anchors = SeekPublicAnchorSet{.selection_anchor = anchor},
        .classification = SeekPublicClassification{.kind = SeekPublicKind::Absolute, .scope = SeekPublicScope::Timeline}
    };
    assert(seek.identity.seek_id.value == 1);
    assert(seek.anchors.selection_anchor.selection_identity.selection_id.value == 123);
    assert(seek.classification.kind == SeekPublicKind::Absolute);
    assert(seek.classification.scope == SeekPublicScope::Timeline);
    SeekPublicOutcome outcome{.identity = SeekPublicIdentity{.seek_id = SeekPublicId{42}}, .status = SeekPublicStatus::Recorded};
    assert(outcome.identity.seek_id.value == 42);
    assert(outcome.status == SeekPublicStatus::Recorded);
    std::cout << "PASS: test_seek_public_boundary_cross_family" << std::endl;
}
