#pragma once
namespace kivo::playback::timeline_result {
enum class TimelineResultSourceKind {
    DecisionRouteIdentity,
    RoutedDecision,
    Synthetic,
    Unknown
};
}
