#include <cassert>
#include <iostream>
#include "audio/contracts/passthrough/audio_passthrough_mode.h"
#include "audio/contracts/passthrough/audio_passthrough_policy.h"
#include "audio/contracts/passthrough/audio_passthrough_status.h"

namespace kivo::playback::audio {
void run_audio_passthrough_tests() {
    // Test AudioPassthroughMode
    AudioPassthroughMode mode1 = AudioPassthroughMode::Disabled;
    AudioPassthroughMode mode2 = AudioPassthroughMode::Preferred;
    AudioPassthroughMode mode3 = AudioPassthroughMode::Required;
    AudioPassthroughMode mode4 = AudioPassthroughMode::Unknown;
    assert(mode1 != mode2);
    assert(mode2 != mode3);
    assert(mode3 != mode4);

    // Test AudioPassthroughPolicy (only mode, no codec/runtime fields)
    AudioPassthroughPolicy policy1;
    assert(policy1.mode == AudioPassthroughMode::Unknown);
    AudioPassthroughPolicy policy2{.mode{AudioPassthroughMode::Preferred}};
    assert(policy2.mode == AudioPassthroughMode::Preferred);

    // Test AudioPassthroughStatus
    AudioPassthroughStatus stat1 = AudioPassthroughStatus::Disabled;
    AudioPassthroughStatus stat2 = AudioPassthroughStatus::Allowed;
    AudioPassthroughStatus stat3 = AudioPassthroughStatus::Required;
    AudioPassthroughStatus stat4 = AudioPassthroughStatus::Rejected;
    AudioPassthroughStatus stat5 = AudioPassthroughStatus::Unknown;
    assert(stat1 != stat2);
    assert(stat2 != stat3);
    assert(stat3 != stat4);
    assert(stat4 != stat5);

    std::cout << "  audio_passthrough_tests: ALL PASSED\n";
}
}
