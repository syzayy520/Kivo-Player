#include <cassert>
#include <iostream>
#include "playback/timeline_error_surface/identity/timeline_error_surface_id.h"
#include "playback/timeline_error_surface/identity/timeline_error_surface_sequence_id.h"
#include "playback/timeline_error_surface/identity/timeline_error_surface_generation.h"
#include "playback/timeline_error_surface/identity/timeline_error_surface_identity.h"
namespace kivo::playback::timeline_error_surface {
void run_timeline_error_identity_tests() {
    TimelineErrorSurfaceId id1; assert(id1.value == 0); TimelineErrorSurfaceId id2{42}; assert(id2.value == 42);
    TimelineErrorSurfaceSequenceId sid1; assert(sid1.value == 0); TimelineErrorSurfaceSequenceId sid2{7}; assert(sid2.value == 7);
    TimelineErrorSurfaceGeneration g1; assert(g1.value == 0); TimelineErrorSurfaceGeneration g2{3}; assert(g2.value == 3);
    TimelineErrorSurfaceIdentity ident1;
    assert(ident1.surface_id.value == 0); assert(ident1.sequence_id.value == 0); assert(ident1.generation.value == 0);
    TimelineErrorSurfaceIdentity ident2{.surface_id{1}, .sequence_id{2}, .generation{3}};
    assert(ident2.surface_id.value == 1); assert(ident2.sequence_id.value == 2); assert(ident2.generation.value == 3);
    std::cout << "  timeline_error_identity_tests: ALL PASSED\n";
}
void run_timeline_error_anchor_tests();
void run_timeline_error_classification_tests();
void run_timeline_error_surface_tests();
void run_timeline_error_outcome_tests();
void run_timeline_error_boundary_tests();
}
int main() {
    using namespace kivo::playback::timeline_error_surface;
    run_timeline_error_identity_tests(); run_timeline_error_anchor_tests();
    run_timeline_error_classification_tests(); run_timeline_error_surface_tests();
    run_timeline_error_outcome_tests(); run_timeline_error_boundary_tests();
    std::cout << "  ALL timeline error surface tests PASSED\n"; return 0;
}
