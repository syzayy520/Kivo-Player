#include <cassert>
#include <iostream>
#include "render/contracts/frame/render_frame_id.h"
#include "render/contracts/frame/render_frame_descriptor.h"
#include "render/contracts/frame/render_frame_timing.h"
#include "render/contracts/frame/render_frame_surface.h"

namespace kivo::playback::render {
void run_render_frame_tests() {
    // Test RenderFrameId
    RenderFrameId frame_id1;
    assert(frame_id1.value == 0);
    RenderFrameId frame_id2{123};
    assert(frame_id2.value == 123);
    
    // Test RenderFrameDescriptor
    RenderFrameDescriptor desc1;
    assert(desc1.frame_id.value == 0);
    assert(desc1.timestamp.value == 0);
    assert(desc1.pixel_format.format_family_id == 0);
    assert(desc1.color_space.primaries == kivo::playback::format::ColorPrimaries::Unknown);
    
    RenderFrameDescriptor desc2{
        .frame_id{456},
        .timestamp{.value{1000}},
        .pixel_format{.format_family_id{1}},
        .color_space{.primaries{kivo::playback::format::ColorPrimaries::BT709}}
    };
    assert(desc2.frame_id.value == 456);
    assert(desc2.timestamp.value == 1000);
    assert(desc2.pixel_format.format_family_id == 1);
    assert(desc2.color_space.primaries == kivo::playback::format::ColorPrimaries::BT709);
    
    // Test RenderFrameTiming
    RenderFrameTiming timing1;
    assert(timing1.pts.value == 0);
    assert(timing1.deadline.deadline_us == 0);
    
    RenderFrameTiming timing2{
        .pts{.value{5000}},
        .deadline{.deadline_us{16666}, .tolerance_us{1000}}
    };
    assert(timing2.pts.value == 5000);
    assert(timing2.deadline.deadline_us == 16666);
    assert(timing2.deadline.tolerance_us == 1000);
    
    // Test RenderFrameSurface
    RenderFrameSurface surface1;
    assert(surface1.frame_id.value == 0);
    assert(surface1.surface.id == 0);
    
    RenderFrameSurface surface2{
        .frame_id{789},
        .surface{.id{0x12345678}}
    };
    assert(surface2.frame_id.value == 789);
    assert(surface2.surface.id == 0x12345678);
    
    std::cout << "  render_frame_tests: ALL PASSED\n";
}
}

// main() is in render_identity_tests.cpp
