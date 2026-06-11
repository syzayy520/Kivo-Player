#include <cassert>
#include <iostream>

#include "playback/buffering_public/buffering/playback_buffering_public.h"
#include "playback/buffering_public/buffering/buffering_public_candidate.h"
#include "playback/buffering_public/buffering/buffering_public_envelope.h"
#include "playback/buffering_public/buffering/buffering_public_record.h"

using namespace kivo::playback::buffering_public;

void test_buffering_public_buffering_default_construction() {
    BufferingPublicCandidate candidate{};
    assert(candidate.identity.buffering_id.value == 0);
    assert(candidate.anchors.seek_anchor.seek_identity.seek_id.value == 0);
    assert(candidate.classification.kind == BufferingPublicKind::Unknown);
    PlaybackBufferingPublic buffering{};
    assert(buffering.identity.buffering_id.value == 0);
    BufferingPublicEnvelope envelope{};
    assert(envelope.identity.buffering_id.value == 0);
    BufferingPublicRecord record{};
    assert(record.envelope.identity.buffering_id.value == 0);
    assert(record.buffering.identity.buffering_id.value == 0);
    std::cout << "PASS: test_buffering_public_buffering_default_construction" << std::endl;
}
