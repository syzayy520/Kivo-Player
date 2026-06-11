#include <cassert>
#include <iostream>

#include "playback/seek_public/seek/playback_seek_public.h"
#include "playback/seek_public/seek/seek_public_candidate.h"
#include "playback/seek_public/seek/seek_public_envelope.h"
#include "playback/seek_public/seek/seek_public_record.h"

using namespace kivo::playback::seek_public;

void test_seek_public_seek_default_construction() {
    SeekPublicCandidate candidate{};
    assert(candidate.identity.seek_id.value == 0);
    assert(candidate.anchors.selection_anchor.selection_identity.selection_id.value == 0);
    assert(candidate.classification.kind == SeekPublicKind::Unknown);
    PlaybackSeekPublic seek{};
    assert(seek.identity.seek_id.value == 0);
    SeekPublicEnvelope envelope{};
    assert(envelope.identity.seek_id.value == 0);
    SeekPublicRecord record{};
    assert(record.envelope.identity.seek_id.value == 0);
    assert(record.seek.identity.seek_id.value == 0);
    std::cout << "PASS: test_seek_public_seek_default_construction" << std::endl;
}
