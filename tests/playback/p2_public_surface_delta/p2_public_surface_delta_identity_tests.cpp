#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_delta/identity/p2_public_surface_delta_identity.h"

using namespace kivo::playback::p2_public_surface_delta;

void test_p2_public_surface_delta_anchor_default_construction();
void test_p2_public_surface_delta_classification_default_construction();
void test_p2_public_surface_delta_delta_default_construction();
void test_p2_public_surface_delta_outcome_default_construction();
void test_p2_public_surface_delta_boundary_cross_family();

int main() {
    P2PublicSurfaceDeltaIdentity identity{};
    assert(identity.delta_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_delta_anchor_default_construction();
    test_p2_public_surface_delta_classification_default_construction();
    test_p2_public_surface_delta_delta_default_construction();
    test_p2_public_surface_delta_outcome_default_construction();
    test_p2_public_surface_delta_boundary_cross_family();
    std::cout << "p2_public_surface_delta tests passed" << std::endl;
    return 0;
}
