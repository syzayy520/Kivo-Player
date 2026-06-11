#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionFallbackPolicy {
    PreserveUnknown,
    PreferHold,
    PreferDrop,
    Unknown
};
}
