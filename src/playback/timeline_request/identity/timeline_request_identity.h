#pragma once
#include "timeline_request_id.h"
#include "timeline_request_sequence_id.h"
#include "timeline_request_generation.h"
namespace kivo::playback::timeline_request {
struct TimelineRequestIdentity {
    TimelineRequestId request_id{};
    TimelineRequestSequenceId sequence_id{};
    TimelineRequestGeneration generation{};
};
}
