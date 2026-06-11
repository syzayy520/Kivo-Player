#include <cassert>
#include <iostream>

#include "playback/public_error_recovery/identity/public_error_recovery_identity.h"

using namespace kivo::playback::public_error_recovery;

void test_public_error_recovery_anchor_default_construction();
void test_public_error_recovery_classification_default_construction();
void test_public_error_recovery_recovery_default_construction();
void test_public_error_recovery_outcome_default_construction();
void test_public_error_recovery_boundary_cross_family();

int main() {
    PublicErrorRecoveryIdentity identity{};
    assert(identity.recovery_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_public_error_recovery_anchor_default_construction();
    test_public_error_recovery_classification_default_construction();
    test_public_error_recovery_recovery_default_construction();
    test_public_error_recovery_outcome_default_construction();
    test_public_error_recovery_boundary_cross_family();
    std::cout << "public_error_recovery tests passed" << std::endl;
    return 0;
}
