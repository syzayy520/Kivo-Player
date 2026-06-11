#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_completion/classification/p2_public_completion_classification.h"

using namespace kivo::playback::p2_public_completion;

void test_p2_public_completion_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicCompletionKind::Acknowledged) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCompletionKind::PartialComplete) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCompletionKind::FullComplete) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCompletionKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicCompletionScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicCompletionScope::ReadbackBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicCompletionScope::CompletionBoundary) == 2);
    assert(static_cast<std::uint8_t>(P2PublicCompletionScope::Unknown) == 3);
    P2PublicCompletionClassification classification{};
    assert(classification.kind == P2PublicCompletionKind::Unknown);
    assert(classification.scope == P2PublicCompletionScope::Unknown);
    std::cout << "PASS: test_p2_public_completion_classification_default_construction" << std::endl;
}
