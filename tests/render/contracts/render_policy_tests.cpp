#include <cassert>
#include <iostream>
#include "render/contracts/policy/render_pacing_policy.h"
#include "render/contracts/policy/render_color_policy.h"
#include "render/contracts/policy/render_hdr_policy.h"
#include "render/contracts/policy/render_failure_policy.h"

namespace kivo::playback::render {
void run_render_policy_tests() {
    // Test RenderPacingPolicy
    RenderPacingPolicy pacing1 = RenderPacingPolicy::Realtime;
    RenderPacingPolicy pacing2 = RenderPacingPolicy::LowLatency;
    RenderPacingPolicy pacing3 = RenderPacingPolicy::BestEffort;
    RenderPacingPolicy pacing4 = RenderPacingPolicy::Offline;
    assert(pacing1 != pacing2);
    assert(pacing2 != pacing3);
    assert(pacing3 != pacing4);
    
    // Test RenderColorPolicy
    RenderColorPolicy color1;
    assert(color1.output_color_space.primaries == kivo::playback::format::ColorPrimaries::Unknown);
    assert(color1.auto_convert == true);
    
    RenderColorPolicy color2{
        .output_color_space{.primaries{kivo::playback::format::ColorPrimaries::BT709}},
        .auto_convert{false}
    };
    assert(color2.output_color_space.primaries == kivo::playback::format::ColorPrimaries::BT709);
    assert(color2.auto_convert == false);
    
    // Test RenderHdrPolicy
    RenderHdrPolicy hdr1;
    assert(hdr1.mode == HdrMode::Off);
    assert(hdr1.hdr_metadata.mastering.max_luminance == 0.0f);
    
    RenderHdrPolicy hdr2{
        .mode{HdrMode::Auto},
        .hdr_metadata{.mastering{.max_luminance{1000.0f}}}
    };
    assert(hdr2.mode == HdrMode::Auto);
    assert(hdr2.hdr_metadata.mastering.max_luminance == 1000.0f);
    
    // Test RenderFailurePolicy
    RenderFailurePolicy failure1 = RenderFailurePolicy::Abort;
    RenderFailurePolicy failure2 = RenderFailurePolicy::SkipFrame;
    RenderFailurePolicy failure3 = RenderFailurePolicy::BlackFrame;
    RenderFailurePolicy failure4 = RenderFailurePolicy::LastGoodFrame;
    assert(failure1 != failure2);
    assert(failure2 != failure3);
    assert(failure3 != failure4);
    
    std::cout << "  render_policy_tests: ALL PASSED\n";
}
}
