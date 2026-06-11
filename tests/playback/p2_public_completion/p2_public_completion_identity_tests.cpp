#include <cassert>
#include <iostream>

#include "playback/p2_public_completion/identity/p2_public_completion_identity.h"

using namespace kivo::playback::p2_public_completion;

void test_p2_public_completion_anchor_default_construction();
void test_p2_public_completion_classification_default_construction();
void test_p2_public_completion_completion_default_construction();
void test_p2_public_completion_outcome_default_construction();
void test_p2_public_completion_boundary_cross_family();

int main() {
    P2PublicCompletionIdentity identity{};
    assert(identity.completion_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_completion_anchor_default_construction();
    test_p2_public_completion_classification_default_construction();
    test_p2_public_completion_completion_default_construction();
    test_p2_public_completion_outcome_default_construction();
    test_p2_public_completion_boundary_cross_family();
    std::cout << "p2_public_completion tests passed" << std::endl;
    return 0;
}
