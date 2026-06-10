#pragma once
#include "audio_render_submission_id.h"
#include "../endpoint/audio_endpoint_id.h"
#include "core/timeline/timestamp/media_timestamp.h"
#include "core/presentation/timing/presentation_deadline.h"
#include "format/contracts/audio/sample_format_descriptor.h"
#include "format/contracts/audio/channel_layout_descriptor.h"
#include "format/contracts/audio/sample_rate_descriptor.h"
namespace kivo::playback::audio {
struct AudioRenderSubmissionRequest {
    AudioRenderSubmissionId submission_id{};
    AudioEndpointId endpoint_id{};
    kivo::playback::timeline::MediaTimestamp presentation_timestamp{};
    kivo::playback::presentation::PresentationDeadline deadline{};
    kivo::playback::format::SampleFormatDescriptor sample_format{};
    kivo::playback::format::ChannelLayoutDescriptor channel_layout{};
    kivo::playback::format::SampleRateDescriptor sample_rate{};
};
}
