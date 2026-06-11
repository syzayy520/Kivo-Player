#include <cassert>
#include <iostream>

#include "playback/p2_public_readback/identity/p2_public_readback_identity.h"

using namespace kivo::playback::p2_public_readback;

void test_p2_public_readback_anchor_default_construction();
void test_p2_public_readback_classification_default_construction();
void test_p2_public_readback_readback_default_construction();
void test_p2_public_readback_outcome_default_construction();
void test_p2_public_readback_boundary_cross_family();

int main() {
    P2PublicReadbackIdentity identity{};
    assert(identity.readback_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_readback_anchor_default_construction();
    test_p2_public_readback_classification_default_construction();
    test_p2_public_readback_readback_default_construction();
    test_p2_public_readback_outcome_default_construction();
    test_p2_public_readback_boundary_cross_family();
    std::cout << "p2_public_readback tests passed" << std::endl;
    return 0;
}
