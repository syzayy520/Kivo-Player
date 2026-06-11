#include <cassert>
#include <iostream>
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_id.h"
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_sequence_id.h"
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_generation.h"
#include "playback/timeline_user_status_surface/identity/timeline_user_status_surface_identity.h"
namespace kivo::playback::timeline_user_status_surface {
void run_timeline_user_status_identity_tests() {
    TimelineUserStatusSurfaceId id1; assert(id1.value == 0); TimelineUserStatusSurfaceId id2{42}; assert(id2.value == 42);
    TimelineUserStatusSurfaceSequenceId sid1; assert(sid1.value == 0); TimelineUserStatusSurfaceSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineUserStatusSurfaceGeneration g1; assert(g1.value == 0); TimelineUserStatusSurfaceGeneration g2{3}; assert(g2.value == 3);
    TimelineUserStatusSurfaceIdentity ident1;
    assert(ident1.surface_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineUserStatusSurfaceIdentity ident2{.surface_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.surface_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_user_status_identity_tests: ALL PASSED\n";
}
void run_timeline_user_status_anchor_tests();
void run_timeline_user_status_classification_tests();
void run_timeline_user_status_surface_tests();
void run_timeline_user_status_outcome_tests();
void run_timeline_user_status_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_user_status_surface;
    run_timeline_user_status_identity_tests(); run_timeline_user_status_anchor_tests();
    run_timeline_user_status_classification_tests(); run_timeline_user_status_surface_tests();
    run_timeline_user_status_outcome_tests(); run_timeline_user_status_boundary_tests();
    std::cout << "  ALL timeline user status surface tests PASSED\n"; return 0;
}
