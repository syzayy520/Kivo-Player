#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_view/identity/p2_public_surface_confirmation_view_identity.h"

using namespace kivo::playback::p2_public_surface_confirmation_view;

void test_p2_public_surface_confirmation_view_anchor_default_construction();
void test_p2_public_surface_confirmation_view_classification_default_construction();
void test_p2_public_surface_confirmation_view_confirmation_view_default_construction();
void test_p2_public_surface_confirmation_view_outcome_default_construction();
void test_p2_public_surface_confirmation_view_boundary_cross_family();

int main() {
    P2PublicSurfaceConfirmationViewIdentity identity{};
    assert(identity.view_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_confirmation_view_anchor_default_construction();
    test_p2_public_surface_confirmation_view_classification_default_construction();
    test_p2_public_surface_confirmation_view_confirmation_view_default_construction();
    test_p2_public_surface_confirmation_view_outcome_default_construction();
    test_p2_public_surface_confirmation_view_boundary_cross_family();
    std::cout << "p2_public_surface_confirmation_view tests passed" << std::endl;
    return 0;
}
