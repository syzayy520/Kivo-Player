#include <cassert>
#include <iostream>

#include "playback/buffering_public/identity/buffering_public_identity.h"

using namespace kivo::playback::buffering_public;

void test_buffering_public_anchor_default_construction();
void test_buffering_public_classification_default_construction();
void test_buffering_public_buffering_default_construction();
void test_buffering_public_outcome_default_construction();
void test_buffering_public_boundary_cross_family();

int main() {
    BufferingPublicIdentity identity{};
    assert(identity.buffering_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_buffering_public_anchor_default_construction();
    test_buffering_public_classification_default_construction();
    test_buffering_public_buffering_default_construction();
    test_buffering_public_outcome_default_construction();
    test_buffering_public_boundary_cross_family();
    std::cout << "buffering_public tests passed" << std::endl;
    return 0;
}
