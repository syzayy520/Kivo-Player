#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionRouteKind {
    Direct,
    Hold,
    Drop,
    Unknown
};
}
