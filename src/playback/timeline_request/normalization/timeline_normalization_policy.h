#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineNormalizationPolicy {
    Strict,
    PreserveTarget,
    PreserveDeadline,
    Unknown
};
}
