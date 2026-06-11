#include <cassert>
#include <iostream>

#include "playback/p2_public_readback/readback/playback_p2_public_readback.h"
#include "playback/p2_public_readback/readback/p2_public_readback_candidate.h"
#include "playback/p2_public_readback/readback/p2_public_readback_envelope.h"
#include "playback/p2_public_readback/readback/p2_public_readback_record.h"

using namespace kivo::playback::p2_public_readback;

void test_p2_public_readback_readback_default_construction() {
    P2PublicReadbackCandidate candidate{};
    assert(candidate.identity.readback_id.value == 0);
    assert(candidate.anchors.admission_anchor.admission_identity.admission_id.value == 0);
    assert(candidate.classification.kind == P2PublicReadbackKind::Unknown);
    PlaybackP2PublicReadback readback{};
    assert(readback.identity.readback_id.value == 0);
    P2PublicReadbackEnvelope envelope{};
    assert(envelope.identity.readback_id.value == 0);
    P2PublicReadbackRecord record{};
    assert(record.envelope.identity.readback_id.value == 0);
    assert(record.readback.identity.readback_id.value == 0);
    std::cout << "PASS: test_p2_public_readback_readback_default_construction" << std::endl;
}
