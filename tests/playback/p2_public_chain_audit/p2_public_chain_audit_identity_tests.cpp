#include <cassert>
#include <iostream>

#include "playback/p2_public_chain_audit/identity/p2_public_chain_audit_identity.h"

using namespace kivo::playback::p2_public_chain_audit;

void test_p2_public_chain_audit_anchor_default_construction();
void test_p2_public_chain_audit_classification_default_construction();
void test_p2_public_chain_audit_audit_default_construction();
void test_p2_public_chain_audit_outcome_default_construction();
void test_p2_public_chain_audit_boundary_cross_family();

int main() {
    P2PublicChainAuditIdentity identity{};
    assert(identity.audit_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_chain_audit_anchor_default_construction();
    test_p2_public_chain_audit_classification_default_construction();
    test_p2_public_chain_audit_audit_default_construction();
    test_p2_public_chain_audit_outcome_default_construction();
    test_p2_public_chain_audit_boundary_cross_family();
    std::cout << "p2_public_chain_audit tests passed" << std::endl;
    return 0;
}
