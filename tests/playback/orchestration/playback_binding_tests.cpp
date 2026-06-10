#include <cassert>
#include <iostream>
#include "playback/orchestration/binding/playback_device_binding.h"
#include "playback/orchestration/binding/playback_audio_binding.h"
#include "playback/orchestration/binding/playback_video_binding.h"
#include "playback/orchestration/binding/playback_output_binding.h"

namespace kivo::playback::orchestration {
void run_playback_binding_tests() {
    PlaybackDeviceBinding dev1;
    assert(dev1.session_id.value == 0);
    assert(dev1.device_id.value == 0);
    PlaybackDeviceBinding dev2{.session_id{PlaybackSessionId{100}}, .device_id{kivo::playback::device::DeviceId{1}}};
    assert(dev2.device_id.value == 1);

    PlaybackAudioBinding aud1;
    assert(aud1.session_id.value == 0);
    assert(aud1.endpoint_id.value == 0);
    PlaybackAudioBinding aud2{.session_id{PlaybackSessionId{200}}, .endpoint_id{kivo::playback::audio::AudioEndpointId{2}}};
    assert(aud2.endpoint_id.value == 2);

    PlaybackVideoBinding vid1;
    assert(vid1.session_id.value == 0);
    assert(vid1.target_id.value == 0);
    PlaybackVideoBinding vid2{.session_id{PlaybackSessionId{300}}, .target_id{kivo::playback::render::RenderTargetId{3}}};
    assert(vid2.target_id.value == 3);

    PlaybackOutputBinding out1;
    assert(out1.session_id.value == 0);
    assert(out1.device.device_id.value == 0);
    assert(out1.audio.endpoint_id.value == 0);
    assert(out1.video.target_id.value == 0);
    PlaybackOutputBinding out2{
        .session_id{PlaybackSessionId{400}},
        .device{.session_id{PlaybackSessionId{400}}, .device_id{kivo::playback::device::DeviceId{10}}},
        .audio{.session_id{PlaybackSessionId{400}}, .endpoint_id{kivo::playback::audio::AudioEndpointId{11}}},
        .video{.session_id{PlaybackSessionId{400}}, .target_id{kivo::playback::render::RenderTargetId{12}}}
    };
    assert(out2.device.device_id.value == 10);
    assert(out2.audio.endpoint_id.value == 11);
    assert(out2.video.target_id.value == 12);

    std::cout << "  playback_binding_tests: ALL PASSED\n";
}
}
