#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionDropReason {
    Superseded,
    PriorityOverridden,
    Unknown
};
}
