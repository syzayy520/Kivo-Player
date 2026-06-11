#include <cassert>
#include <iostream>

#include "playback/p2_public_completion/identity/p2_public_completion_identity.h"
#include "playback/p2_public_completion/anchor/p2_public_readback_completion_anchor.h"
#include "playback/p2_public_completion/completion/playback_p2_public_completion.h"
#include "playback/p2_public_completion/outcome/p2_public_completion_outcome.h"

using namespace kivo::playback::p2_public_completion;

void test_p2_public_completion_boundary_cross_family() {
    P2PublicReadbackCompletionAnchor anchor{};
    anchor.readback_identity.readback_id = kivo::playback::p2_public_readback::P2PublicReadbackId{123};
    assert(anchor.readback_identity.readback_id.value == 123);
    PlaybackP2PublicCompletion completion{
        .identity = P2PublicCompletionIdentity{.completion_id = P2PublicCompletionId{1}},
        .anchors = P2PublicCompletionAnchorSet{.readback_anchor = anchor},
        .classification = P2PublicCompletionClassification{.kind = P2PublicCompletionKind::FullComplete, .scope = P2PublicCompletionScope::CompletionBoundary}
    };
    assert(completion.identity.completion_id.value == 1);
    assert(completion.anchors.readback_anchor.readback_identity.readback_id.value == 123);
    assert(completion.classification.kind == P2PublicCompletionKind::FullComplete);
    assert(completion.classification.scope == P2PublicCompletionScope::CompletionBoundary);
    P2PublicCompletionOutcome outcome{.identity = P2PublicCompletionIdentity{.completion_id = P2PublicCompletionId{42}}, .status = P2PublicCompletionStatus::Recorded};
    assert(outcome.identity.completion_id.value == 42);
    assert(outcome.status == P2PublicCompletionStatus::Recorded);
    std::cout << "PASS: test_p2_public_completion_boundary_cross_family" << std::endl;
}
