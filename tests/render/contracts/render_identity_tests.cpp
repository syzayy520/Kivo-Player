#include <cassert>
#include <iostream>
#include "render/contracts/identity/renderer_id.h"
#include "render/contracts/identity/renderer_role.h"
#include "render/contracts/identity/renderer_identity.h"

namespace kivo::playback::render {
void run_render_identity_tests() {
    // Test RendererId
    RendererId id1;
    assert(id1.value == 0);
    RendererId id2{42};
    assert(id2.value == 42);
    
    // Test RendererRole
    RendererRole role1 = RendererRole::PrimaryVideo;
    RendererRole role2 = RendererRole::SecondaryVideo;
    RendererRole role3 = RendererRole::DiagnosticVideo;
    RendererRole role4 = RendererRole::Unknown;
    assert(role1 != role2);
    assert(role2 != role3);
    assert(role3 != role4);
    
    // Test RendererIdentity
    RendererIdentity identity1;
    assert(identity1.id.value == 0);
    assert(identity1.role == RendererRole::Unknown);
    
    RendererIdentity identity2{.id{100}, .role{RendererRole::PrimaryVideo}};
    assert(identity2.id.value == 100);
    assert(identity2.role == RendererRole::PrimaryVideo);
    
    std::cout << "  render_identity_tests: ALL PASSED\n";
}

// Forward declarations for other test suites
void run_render_frame_tests();
void run_render_target_tests();
void run_render_submission_tests();
void run_render_policy_tests();
void run_render_outcome_tests();
}

int main() {
    using namespace kivo::playback::render;
    run_render_identity_tests();
    run_render_frame_tests();
    run_render_target_tests();
    run_render_submission_tests();
    run_render_policy_tests();
    run_render_outcome_tests();
    std::cout << "  ALL render contracts tests PASSED\n";
    return 0;
}
