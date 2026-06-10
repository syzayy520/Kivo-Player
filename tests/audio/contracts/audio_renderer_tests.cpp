#include <cassert>
#include <iostream>
#include "audio/contracts/renderer/audio_renderer_id.h"
#include "audio/contracts/renderer/audio_renderer_role.h"
#include "audio/contracts/renderer/audio_renderer_identity.h"

namespace kivo::playback::audio {
void run_audio_renderer_tests() {
    // Test AudioRendererId
    AudioRendererId id1;
    assert(id1.value == 0);
    AudioRendererId id2{99};
    assert(id2.value == 99);

    // Test AudioRendererRole
    AudioRendererRole role1 = AudioRendererRole::PrimaryAudio;
    AudioRendererRole role2 = AudioRendererRole::SecondaryAudio;
    AudioRendererRole role3 = AudioRendererRole::PassthroughOnly;
    AudioRendererRole role4 = AudioRendererRole::Unknown;
    assert(role1 != role2);
    assert(role2 != role3);
    assert(role3 != role4);

    // Test AudioRendererIdentity
    AudioRendererIdentity identity1;
    assert(identity1.id.value == 0);
    assert(identity1.role == AudioRendererRole::Unknown);
    AudioRendererIdentity identity2{.id{50}, .role{AudioRendererRole::PrimaryAudio}};
    assert(identity2.id.value == 50);
    assert(identity2.role == AudioRendererRole::PrimaryAudio);

    std::cout << "  audio_renderer_tests: ALL PASSED\n";
}
}
