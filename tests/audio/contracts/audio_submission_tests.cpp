#include <cassert>
#include <iostream>
#include "audio/contracts/submission/audio_render_submission_id.h"
#include "audio/contracts/submission/audio_render_submission_request.h"
#include "audio/contracts/submission/audio_render_submission_result.h"
#include "audio/contracts/submission/audio_render_submission_status.h"

namespace kivo::playback::audio {
void run_audio_submission_tests() {
    // Test AudioRenderSubmissionId
    AudioRenderSubmissionId sid1;
    assert(sid1.value == 0);
    AudioRenderSubmissionId sid2{111222};
    assert(sid2.value == 111222);

    // Test AudioRenderSubmissionRequest (consumes P0-006/008/011 via real fields)
    AudioRenderSubmissionRequest request1;
    assert(request1.submission_id.value == 0);
    assert(request1.endpoint_id.value == 0);
    assert(request1.presentation_timestamp.value == 0);
    assert(request1.deadline.deadline_us == 0);
    assert(request1.sample_format.format_family_id == 0);
    assert(request1.channel_layout.channel_count == 0);
    assert(request1.sample_rate.rate_hz == 0);
    AudioRenderSubmissionRequest request2{
        .submission_id{AudioRenderSubmissionId{333444}},
        .endpoint_id{AudioEndpointId{555}},
        .presentation_timestamp{kivo::playback::timeline::MediaTimestamp{{}, 90000}},
        .deadline{kivo::playback::presentation::PresentationDeadline{33333, 1000}},
        .sample_format{kivo::playback::format::SampleFormatDescriptor{1, 16, false, false}},
        .channel_layout{kivo::playback::format::ChannelLayoutDescriptor{0x3, 2}},
        .sample_rate{kivo::playback::format::SampleRateDescriptor{48000}}
    };
    assert(request2.submission_id.value == 333444);
    assert(request2.presentation_timestamp.value == 90000);
    assert(request2.deadline.deadline_us == 33333);
    assert(request2.sample_format.bits_per_sample == 16);
    assert(request2.channel_layout.channel_count == 2);
    assert(request2.sample_rate.rate_hz == 48000);

    // Test AudioRenderSubmissionResult
    AudioRenderSubmissionResult result1;
    assert(result1.submission_id.value == 0);
    assert(result1.status == AudioRenderSubmissionStatus::Unknown);
    assert(result1.frames_accepted == 0);
    assert(result1.frames_dropped == 0);
    AudioRenderSubmissionResult result2{
        .submission_id{AudioRenderSubmissionId{555666}},
        .status{AudioRenderSubmissionStatus::Accepted},
        .frames_accepted{1024},
        .frames_dropped{0}
    };
    assert(result2.submission_id.value == 555666);
    assert(result2.status == AudioRenderSubmissionStatus::Accepted);
    assert(result2.frames_accepted == 1024);
    assert(result2.frames_dropped == 0);

    // Test AudioRenderSubmissionStatus
    AudioRenderSubmissionStatus sstat1 = AudioRenderSubmissionStatus::Accepted;
    AudioRenderSubmissionStatus sstat2 = AudioRenderSubmissionStatus::Partial;
    AudioRenderSubmissionStatus sstat3 = AudioRenderSubmissionStatus::Rejected;
    AudioRenderSubmissionStatus sstat4 = AudioRenderSubmissionStatus::Queued;
    AudioRenderSubmissionStatus sstat5 = AudioRenderSubmissionStatus::Unknown;
    assert(sstat1 != sstat2);
    assert(sstat2 != sstat3);
    assert(sstat3 != sstat4);
    assert(sstat4 != sstat5);

    std::cout << "  audio_submission_tests: ALL PASSED\n";
}
}
