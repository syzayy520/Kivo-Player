#include <cassert>
#include <iostream>

#include "playback/end_of_stream_public/end/playback_end_of_stream_public.h"
#include "playback/end_of_stream_public/end/end_of_stream_public_candidate.h"
#include "playback/end_of_stream_public/end/end_of_stream_public_envelope.h"
#include "playback/end_of_stream_public/end/end_of_stream_public_record.h"

using namespace kivo::playback::end_of_stream_public;

void test_end_of_stream_public_end_default_construction() {
    EndOfStreamPublicCandidate candidate{};
    assert(candidate.identity.end_id.value == 0);
    assert(candidate.anchors.transition_anchor.transition_identity.transition_id.value == 0);
    assert(candidate.classification.kind == EndOfStreamPublicKind::Unknown);
    PlaybackEndOfStreamPublic end{};
    assert(end.identity.end_id.value == 0);
    EndOfStreamPublicEnvelope envelope{};
    assert(envelope.identity.end_id.value == 0);
    EndOfStreamPublicRecord record{};
    assert(record.envelope.identity.end_id.value == 0);
    assert(record.end.identity.end_id.value == 0);
    std::cout << "PASS: test_end_of_stream_public_end_default_construction" << std::endl;
}
