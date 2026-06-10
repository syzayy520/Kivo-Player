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
    
    // Test RenderTargetState (approved: Uninitialized,Active,Suspended,Resized,Inactive,Unknown)
    RenderTargetState state1 = RenderTargetState::Uninitialized;
    RenderTargetState state2 = RenderTargetState::Active;
    RenderTargetState state3 = RenderTargetState::Suspended;
    RenderTargetState state4 = RenderTargetState::Resized;
    RenderTargetState state5 = RenderTargetState::Inactive;
    RenderTargetState state6 = RenderTargetState::Unknown;
    assert(state1 != state2);
    assert(state2 != state3);
    assert(state3 != state4);
    assert(state4 != state5);
    assert(state5 != state6);
    
    // Test RenderTargetGeneration (approved: { uint64_t value })
    RenderTargetGeneration gen1;
    assert(gen1.value == 0);
    RenderTargetGeneration gen2{42};
    assert(gen2.value == 42);
    
    // Test RenderTargetDeviceBinding (approved: target_id + DeviceId + DeviceGeneration)
    RenderTargetDeviceBinding binding1;
    assert(binding1.target_id.value == 0);
    assert(binding1.device_id.value == 0);
    assert(binding1.device_generation.value == 0);
    RenderTargetDeviceBinding binding2{
        .target_id{131415},
        .device_id{kivo::playback::device::DeviceId{161718}},
        .device_generation{kivo::playback::device::DeviceGeneration{42}}
    };
    assert(binding2.target_id.value == 131415);
    assert(binding2.device_id.value == 161718);
    assert(binding2.device_generation.value == 42);
    
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
