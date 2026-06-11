#include <cassert>
#include <iostream>

#include "playback/p2_public_surface_confirmation_audit/identity/p2_public_surface_confirmation_audit_identity.h"

using namespace kivo::playback::p2_public_surface_confirmation_audit;

void test_p2_public_surface_confirmation_audit_anchor_default_construction();
void test_p2_public_surface_confirmation_audit_classification_default_construction();
void test_p2_public_surface_confirmation_audit_audit_default_construction();
void test_p2_public_surface_confirmation_audit_outcome_default_construction();
void test_p2_public_surface_confirmation_audit_boundary_cross_family();

int main() {
    P2PublicSurfaceConfirmationAuditIdentity identity{};
    assert(identity.audit_id.value == 0);
    assert(identity.sequence_id.value == 0);
    assert(identity.generation.value == 0);
    test_p2_public_surface_confirmation_audit_anchor_default_construction();
    test_p2_public_surface_confirmation_audit_classification_default_construction();
    test_p2_public_surface_confirmation_audit_audit_default_construction();
    test_p2_public_surface_confirmation_audit_outcome_default_construction();
    test_p2_public_surface_confirmation_audit_boundary_cross_family();
    std::cout << "p2_public_surface_confirmation_audit tests passed" << std::endl;
    return 0;
}
