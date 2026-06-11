#include <cassert>
#include <cstdint>
#include <iostream>

#include "playback/p2_public_chain_audit/classification/p2_public_chain_audit_classification.h"

using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_chain_audit_classification_default_construction() {
    assert(static_cast<std::uint8_t>(P2PublicChainAuditKind::CompletionClosed) == 0);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditKind::ChainClosed) == 1);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditKind::ProofOnly) == 2);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditKind::Unknown) == 3);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditScope::PublicSurface) == 0);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditScope::CompletionBoundary) == 1);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditScope::P2Chain) == 2);
    assert(static_cast<std::uint8_t>(P2PublicChainAuditScope::Unknown) == 3);
    P2PublicChainAuditClassification classification{};
    assert(classification.kind == P2PublicChainAuditKind::Unknown);
    assert(classification.scope == P2PublicChainAuditScope::Unknown);
    std::cout << "PASS: test_p2_public_chain_audit_classification_default_construction" << std::endl;
}
