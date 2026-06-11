#include <cassert>
#include <iostream>

#include "playback/p2_public_completion/completion/playback_p2_public_completion.h"
#include "playback/p2_public_completion/completion/p2_public_completion_candidate.h"
#include "playback/p2_public_completion/completion/p2_public_completion_envelope.h"
#include "playback/p2_public_completion/completion/p2_public_completion_record.h"

using namespace kivo::playback::p2_public_completion;

void test_p2_public_completion_completion_default_construction() {
    P2PublicCompletionCandidate candidate{};
    assert(candidate.identity.completion_id.value == 0);
    assert(candidate.anchors.readback_anchor.readback_identity.readback_id.value == 0);
    assert(candidate.classification.kind == P2PublicCompletionKind::Unknown);
    PlaybackP2PublicCompletion completion{};
    assert(completion.identity.completion_id.value == 0);
    P2PublicCompletionEnvelope envelope{};
    assert(envelope.identity.completion_id.value == 0);
    P2PublicCompletionRecord record{};
    assert(record.envelope.identity.completion_id.value == 0);
    assert(record.completion.identity.completion_id.value == 0);
    std::cout << "PASS: test_p2_public_completion_completion_default_construction" << std::endl;
}
