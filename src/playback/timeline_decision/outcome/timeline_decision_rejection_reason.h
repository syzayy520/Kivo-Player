#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionRejectionReason {
    InputInvalid,
    DecisionUnavailable,
    RoutePolicyInvalid,
    Unknown
};
}
