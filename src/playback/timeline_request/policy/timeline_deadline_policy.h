#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineDeadlinePolicy {
    None,
    Preserve,
    Required,
    Unknown
};
}
