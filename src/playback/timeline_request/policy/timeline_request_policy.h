#pragma once
#include "timeline_deadline_policy.h"
#include "timeline_clamp_policy.h"
#include "timeline_request_priority.h"
#include "core/presentation/timing/presentation_deadline.h"
namespace kivo::playback::timeline_request {
struct TimelineRequestPolicy {
    TimelineDeadlinePolicy deadline_policy{TimelineDeadlinePolicy::Unknown};
    TimelineClampPolicy clamp_policy{TimelineClampPolicy::Unknown};
    TimelineRequestPriority priority{TimelineRequestPriority::Unknown};
    kivo::playback::presentation::PresentationDeadline deadline{};
};
}
