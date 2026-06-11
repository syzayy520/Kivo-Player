#pragma once
namespace kivo::playback::timeline_request {
enum class TimelineDropReason {
    Superseded,
    PriorityOverridden,
    Unknown
};
}
