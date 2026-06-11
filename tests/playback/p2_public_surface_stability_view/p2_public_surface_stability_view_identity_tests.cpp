#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_stability_view/identity/p2_public_surface_stability_view_identity.h"

using namespace kivo::playback::p2_public_surface_stability_view;

void test_p2_public_surface_stability_view_anchor_default_construction();
void test_p2_public_surface_stability_view_classification_default_construction();
void test_p2_public_surface_stability_view_stability_view_default_construction();
void test_p2_public_surface_stability_view_outcome_default_construction();
void test_p2_public_surface_stability_view_boundary_cross_family();

int main() {
    P2PublicSurfaceStabilityViewIdentity identity{};
    assert(identity.view_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_stability_view_anchor_default_construction();
    test_p2_public_surface_stability_view_classification_default_construction();
    test_p2_public_surface_stability_view_stability_view_default_construction();
    test_p2_public_surface_stability_view_outcome_default_construction();
    test_p2_public_surface_stability_view_boundary_cross_family();
    std::cout << "p2_public_surface_stability_view tests passed" << std::endl;
    return 0;
}
