#include <cassert>
#include <iostream>
#include "subtitle/contracts/overlay/overlay_plane_id.h"
#include "subtitle/contracts/overlay/overlay_plane_role.h"
#include "subtitle/contracts/overlay/overlay_plane_descriptor.h"
#include "subtitle/contracts/overlay/overlay_blend_mode.h"

namespace kivo::playback::subtitle {
void run_subtitle_overlay_tests() {
    // Test OverlayPlaneId
    OverlayPlaneId id1;
    assert(id1.value == 0);
    OverlayPlaneId id2{456};
    assert(id2.value == 456);

    // Test OverlayPlaneRole
    OverlayPlaneRole r1 = OverlayPlaneRole::SubtitlePlane;
    OverlayPlaneRole r2 = OverlayPlaneRole::OnScreenDisplay;
    assert(r1 != r2);

    // Test OverlayPlaneDescriptor
    OverlayPlaneDescriptor desc1;
    assert(desc1.plane_id.value == 0);
    assert(desc1.role == OverlayPlaneRole::Unknown);
    assert(desc1.surface.id == 0);
    assert(desc1.width == 0);
    assert(desc1.height == 0);
    assert(desc1.pixel_format.format_family_id == 0);
    assert(desc1.color_space.primaries == kivo::playback::format::ColorPrimaries::Unknown);
    OverlayPlaneDescriptor desc2{
        .plane_id{10},
        .role{OverlayPlaneRole::SubtitlePlane},
        .surface{kivo::playback::memory::SurfaceHandle{0xABCD}},
        .width{1920},
        .height{1080},
        .pixel_format{kivo::playback::format::PixelFormatDescriptor{1}},
        .color_space{.primaries{kivo::playback::format::ColorPrimaries::BT709}}
    };
    assert(desc2.plane_id.value == 10);
    assert(desc2.surface.id == 0xABCD);
    assert(desc2.width == 1920);
    assert(desc2.height == 1080);

    // Test OverlayBlendMode
    OverlayBlendMode bm1 = OverlayBlendMode::Opaque;
    OverlayBlendMode bm2 = OverlayBlendMode::SourceOver;
    assert(bm1 != bm2);

    std::cout << "  subtitle_overlay_tests: ALL PASSED\n";
}
}
