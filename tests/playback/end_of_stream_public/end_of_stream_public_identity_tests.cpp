#include <cassert>
#include <iostream>

#include "playback/end_of_stream_public/identity/end_of_stream_public_identity.h"

using namespace kivo::playback::end_of_stream_public;

void test_end_of_stream_public_anchor_default_construction();
void test_end_of_stream_public_classification_default_construction();
void test_end_of_stream_public_end_default_construction();
void test_end_of_stream_public_outcome_default_construction();
void test_end_of_stream_public_boundary_cross_family();

int main() {
    EndOfStreamPublicIdentity identity{};
    assert(identity.end_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_end_of_stream_public_anchor_default_construction();
    test_end_of_stream_public_classification_default_construction();
    test_end_of_stream_public_end_default_construction();
    test_end_of_stream_public_outcome_default_construction();
    test_end_of_stream_public_boundary_cross_family();
    std::cout << "end_of_stream_public tests passed" << std::endl;
    return 0;
}
