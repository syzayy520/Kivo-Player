#include <cassert>
#include <iostream>

#include "playback/p2_public_command_admission/identity/p2_public_command_admission_identity.h"

using namespace kivo::playback::p2_public_command_admission;

void test_p2_public_command_admission_anchor_default_construction();
void test_p2_public_command_admission_classification_default_construction();
void test_p2_public_command_admission_admission_default_construction();
void test_p2_public_command_admission_outcome_default_construction();
void test_p2_public_command_admission_boundary_cross_family();

int main() {
    P2PublicCommandAdmissionIdentity identity{};
    assert(identity.admission_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_command_admission_anchor_default_construction();
    test_p2_public_command_admission_classification_default_construction();
    test_p2_public_command_admission_admission_default_construction();
    test_p2_public_command_admission_outcome_default_construction();
    test_p2_public_command_admission_boundary_cross_family();
    std::cout << "p2_public_command_admission tests passed" << std::endl;
    return 0;
}
