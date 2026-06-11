#pragma once
#include "playback/timeline_request/normalization/timeline_request_envelope.h"
namespace kivo::playback::timeline_decision {
struct TimelineRequestEnvelopeInput {
    kivo::playback::timeline_request::TimelineRequestEnvelope envelope{};
};
}
