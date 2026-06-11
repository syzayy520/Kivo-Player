#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionRouteStatus {
    Routed,
    Rejected,
    Dropped,
    Unknown
};
}
