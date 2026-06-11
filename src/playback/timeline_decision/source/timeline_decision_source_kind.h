#pragma once
namespace kivo::playback::timeline_decision {
enum class TimelineDecisionSourceKind {
    RequestIdentity,
    NormalizedRequest,
    Synthetic,
    Unknown
};
}
