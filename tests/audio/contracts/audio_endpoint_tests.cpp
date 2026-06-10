#include <cassert>
#include <iostream>
#include "audio/contracts/endpoint/audio_endpoint_id.h"
#include "audio/contracts/endpoint/audio_endpoint_role.h"
#include "audio/contracts/endpoint/audio_endpoint_identity.h"
#include "audio/contracts/endpoint/audio_endpoint_device_binding.h"
#include "audio/contracts/endpoint/audio_endpoint_capability_snapshot.h"

namespace kivo::playback::audio {
void run_audio_endpoint_tests() {
    // Test AudioEndpointId
    AudioEndpointId id1;
    assert(id1.value == 0);
    AudioEndpointId id2{42};
    assert(id2.value == 42);

    // Test AudioEndpointRole (no Capture/Loopback/Input/Recording/Monitor)
    AudioEndpointRole role1 = AudioEndpointRole::PrimaryPlayback;
    AudioEndpointRole role2 = AudioEndpointRole::SecondaryPlayback;
    AudioEndpointRole role3 = AudioEndpointRole::DiagnosticPlayback;
    AudioEndpointRole role4 = AudioEndpointRole::Unknown;
    assert(role1 != role2);
    assert(role2 != role3);
    assert(role3 != role4);

    // Test AudioEndpointIdentity
    AudioEndpointIdentity identity1;
    assert(identity1.id.value == 0);
    assert(identity1.role == AudioEndpointRole::Unknown);
    AudioEndpointIdentity identity2{.id{100}, .role{AudioEndpointRole::PrimaryPlayback}};
    assert(identity2.id.value == 100);
    assert(identity2.role == AudioEndpointRole::PrimaryPlayback);

    // Test AudioEndpointDeviceBinding (consumes DeviceId + DeviceGeneration)
    AudioEndpointDeviceBinding binding1;
    assert(binding1.endpoint_id.value == 0);
    assert(binding1.device_id.value == 0);
    assert(binding1.device_generation.value == 0);
    AudioEndpointDeviceBinding binding2{
        .endpoint_id{200},
        .device_id{kivo::playback::device::DeviceId{300}},
        .device_generation{kivo::playback::device::DeviceGeneration{5}}
    };
    assert(binding2.endpoint_id.value == 200);
    assert(binding2.device_id.value == 300);
    assert(binding2.device_generation.value == 5);

    // Test AudioEndpointCapabilitySnapshot
    AudioEndpointCapabilitySnapshot snapshot1;
    assert(snapshot1.endpoint_id.value == 0);
    assert(snapshot1.capability_result.level == kivo::playback::capability::CapabilityLevel::Unknown);
    assert(snapshot1.negotiation_result.match == kivo::playback::capability::NegotiationMatch::Rejected);
    AudioEndpointCapabilitySnapshot snapshot2{
        .endpoint_id{400},
        .capability_result{.level{kivo::playback::capability::CapabilityLevel::Full}},
        .negotiation_result{.match{kivo::playback::capability::NegotiationMatch::ExactMatch}}
    };
    assert(snapshot2.endpoint_id.value == 400);
    assert(snapshot2.capability_result.level == kivo::playback::capability::CapabilityLevel::Full);
    assert(snapshot2.negotiation_result.match == kivo::playback::capability::NegotiationMatch::ExactMatch);

    std::cout << "  audio_endpoint_tests: ALL PASSED\n";
}

void run_audio_renderer_tests();
void run_audio_clock_tests();
void run_audio_submission_tests();
void run_audio_passthrough_tests();
void run_audio_outcome_tests();
}

int main() {
    using namespace kivo::playback::audio;
    run_audio_endpoint_tests();
    run_audio_renderer_tests();
    run_audio_clock_tests();
    run_audio_submission_tests();
    run_audio_passthrough_tests();
    run_audio_outcome_tests();
    std::cout << "  ALL audio contracts tests PASSED\n";
    return 0;
}
