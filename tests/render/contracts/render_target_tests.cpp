#include <cassert>
#include <iostream>
#include "render/contracts/target/render_target_id.h"
#include "render/contracts/target/render_target_descriptor.h"
#include "render/contracts/target/render_target_state.h"
#include "render/contracts/target/render_target_generation.h"
#include "render/contracts/target/render_target_device_binding.h"
#include "render/contracts/target/render_target_capability_snapshot.h"

namespace kivo::playback::render {
void run_render_target_tests() {
    // Test RenderTargetId
    RenderTargetId target_id1;
    assert(target_id1.value == 0);
    RenderTargetId target_id2{789};
    assert(target_id2.value == 789);
    
    // Test RenderTargetDescriptor
    RenderTargetDescriptor desc1;
    assert(desc1.target_id.value == 0);
    assert(desc1.width == 0);
    assert(desc1.height == 0);
    assert(desc1.pixel_format_hint.format_family_id == 0);
    assert(desc1.color_space_hint.primaries == kivo::playback::format::ColorPrimaries::Unknown);
    
    RenderTargetDescriptor desc2{
        .target_id{101112},
        .width{1920},
        .height{1080},
        .pixel_format_hint{.format_family_id{2}},
        .color_space_hint{.primaries{kivo::playback::format::ColorPrimaries::BT709}}
    };
    assert(desc2.target_id.value == 101112);
    assert(desc2.width == 1920);
    assert(desc2.height == 1080);
    assert(desc2.pixel_format_hint.format_family_id == 2);
    assert(desc2.color_space_hint.primaries == kivo::playback::format::ColorPrimaries::BT709);
    
    // Test RenderTargetState
    RenderTargetState state1 = RenderTargetState::Active;
    RenderTargetState state2 = RenderTargetState::Suspended;
    RenderTargetState state3 = RenderTargetState::Lost;
    RenderTargetState state4 = RenderTargetState::Closed;
    assert(state1 != state2);
    assert(state2 != state3);
    assert(state3 != state4);
    
    // Test RenderTargetGeneration
    RenderTargetGeneration gen1;
    assert(gen1.device_gen.value == 0);
    RenderTargetGeneration gen2{.device_gen{.value{42}}};
    assert(gen2.device_gen.value == 42);
    
    // Test RenderTargetDeviceBinding
    RenderTargetDeviceBinding binding1;
    assert(binding1.target_id.value == 0);
    assert(binding1.device.value == 0);
    RenderTargetDeviceBinding binding2{
        .target_id{131415},
        .device{.value{161718}}
    };
    assert(binding2.target_id.value == 131415);
    assert(binding2.device.value == 161718);
    
    // Test RenderTargetCapabilitySnapshot
    RenderTargetCapabilitySnapshot snapshot1;
    assert(snapshot1.target_id.value == 0);
    assert(snapshot1.capability_result.level == kivo::playback::capability::CapabilityLevel::Unknown);
    assert(snapshot1.negotiation_result.match == kivo::playback::capability::NegotiationMatch::Rejected);
    
    RenderTargetCapabilitySnapshot snapshot2{
        .target_id{192021},
        .capability_result{.level{kivo::playback::capability::CapabilityLevel::Full}},
        .negotiation_result{.match{kivo::playback::capability::NegotiationMatch::ExactMatch}}
    };
    assert(snapshot2.target_id.value == 192021);
    assert(snapshot2.capability_result.level == kivo::playback::capability::CapabilityLevel::Full);
    assert(snapshot2.negotiation_result.match == kivo::playback::capability::NegotiationMatch::ExactMatch);
    
    std::cout << "  render_target_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
