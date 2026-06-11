#pragma once
#include "../identity/timeline_request_identity.h"
#include "../source/timeline_request_source.h"
#include "../target/timeline_request_target.h"
#include "../policy/timeline_request_policy.h"
namespace kivo::playback::timeline_request {
struct TimelineRequestEnvelope {
    TimelineRequestIdentity identity{};
    TimelineRequestSource source{};
    TimelineRequestTarget target{};
    TimelineRequestPolicy policy{};
};
}
