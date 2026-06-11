#include <cassert>
#include <iostream>

#include "playback/p2_public_intake/identity/p2_public_intake_identity.h"

using namespace kivo::playback::p2_public_intake;

void test_p2_public_intake_anchor_default_construction();
void test_p2_public_intake_classification_default_construction();
void test_p2_public_intake_intake_default_construction();
void test_p2_public_intake_outcome_default_construction();
void test_p2_public_intake_boundary_cross_family();

int main() {
    P2PublicIntakeIdentity identity{};
    assert(identity.intake_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_intake_anchor_default_construction();
    test_p2_public_intake_classification_default_construction();
    test_p2_public_intake_intake_default_construction();
    test_p2_public_intake_outcome_default_construction();
    test_p2_public_intake_boundary_cross_family();
    std::cout << "p2_public_intake tests passed" << std::endl;
    return 0;
}
