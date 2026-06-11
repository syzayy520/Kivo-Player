#include <cassert>
#include <iostream>

#include "playback/seek_public/identity/seek_public_identity.h"

using namespace kivo::playback::seek_public;

void test_seek_public_anchor_default_construction();
void test_seek_public_classification_default_construction();
void test_seek_public_seek_default_construction();
void test_seek_public_outcome_default_construction();
void test_seek_public_boundary_cross_family();

int main() {
    SeekPublicIdentity identity{};
    assert(identity.seek_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_seek_public_anchor_default_construction();
    test_seek_public_classification_default_construction();
    test_seek_public_seek_default_construction();
    test_seek_public_outcome_default_construction();
    test_seek_public_boundary_cross_family();
    std::cout << "seek_public tests passed" << std::endl;
    return 0;
}
